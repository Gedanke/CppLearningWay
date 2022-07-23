#  对话框 QDialog

---

## 基本概念

对话框是 GUI 程序中不可或缺的组成部分。很多不能或者不适合放入主窗口的功能组件都必须放在对话框中设置。对话框通常会是一个顶层窗口，出现在程序最上层，用于实现短期任务或者简洁的用户交互

Qt 中使用 `QDialog` 类实现对话框。就像主窗口一样，我们通常会设计一个类继承 `QDialog`。`QDialog`(及其子类，以及所有 `Qt::Dialog` 类型的类)对于其 `parent` 指针都有额外的解释：如果 `parent`为 `NULL`，则该对话框会作为一个顶层窗口，否则则作为其父组件的子对话框(此时，其默认出现的位置是 `parent` 的中心)。顶层窗口与非顶层窗口的区别在于，顶层窗口在任务栏会有自己的位置，而非顶层窗口则会共享其父组件的位置

对话框分为模态对话框和非模态对话框。

* 模态对话框，就是会阻塞同一应用程序中其它窗口的输入
    * 模态对话框很常见，比如 `打开文件` 功能。如记事本的打开文件，当打开文件对话框出现时，我们是不能对除此对话框之外的窗口部分进行操作的
* 与此相反的是非模态对话框，例如查找对话框，我们可以在显示着查找对话框的同时，继续对记事本的内容进行编辑

---

## 标准对话框

所谓标准对话框，是 Qt 内置的一系列对话框，用于简化开发。事实上，有很多对话框都是通用的，比如打开文件、设置颜色、打印设置等。这些对话框在所有程序中几乎相同，因此没有必要在每一个程序中都自己实现这么一个对话框

Qt 的内置对话框大致分为以下几类：

* `QColorDialog`: 选择颜色
* `QFileDialog`: 选择文件或者目录
* `QFontDialog`: 选择字体
* `QInputDialog`: 允许用户输入一个值，并将其值返回
* `QMessageBox`: 模态对话框，用于显示信息、询问问题等
* `QPageSetupDialog`: 为打印机提供纸张相关的选项
* `QPrintDialog`: 打印机配置
* `QPrintPreviewDialog`: 打印预览
* `QProgressDialog`: 显示操作过程

---

## 自定义消息框

Qt 支持模态对话框和非模态对话框

模态与非模态的实现：

* 使用 `QDialog::exec()` 实现应用程序级别的模态对话框
* 使用 `QDialog::open()` 实现窗口级别的模态对话框
* 使用 `QDialog::show()` 实现非模态对话框

### 模态对话框

Qt 有两种级别的模态对话框：

* 应用程序级别的模态。当该种模态的对话框出现时，用户必须首先对对话框进行交互，直到关闭对话框，然后才能访问程序中其他的窗口
* 窗口级别的模态。该模态仅仅阻塞与对话框关联的窗口，但是依然允许用户与程序中其它窗口交互。窗口级别的模态尤其适用于多窗口模式

一般默认是应用程序级别的模态

在下面的示例中，我们调用了 `exec()` 将对话框显示出来，因此这就是一个模态对话框。当对话框出现时，我们不能与主窗口进行任何交互，直到关闭了该对话框

```cpp
QDialog dialog;
dialog.setWindowTitle(tr("Hello, dialog!"));
dialog.exec();
```

### 非模态对话框

下面我们试着将 `exec()` 修改为 `show()`，看看非模态对话框：

```cpp
QDialog dialog(this);
dialog.setWindowTitle(tr("Hello, dialog!"));
dialog.show();
```

对话框竟然一闪而过。这是因为，`show()` 函数不会阻塞当前线程，对话框会显示出来，然后函数立即返回，代码继续执行。注意，`dialog` 是建立在栈上的，`show()` 函数返回，`MainWindow::open()` 函数结束，`dialog` 超出作用域被析构，因此对话框消失了。知道了原因就好改了，将 `dialog` 改成堆上建立，当然就没有这个问题了:

```cpp
QDialog *dialog = new QDialog;
dialog->setWindowTitle(tr("Hello, dialog!"));
dialog->show();
```

如果你足够细心，应该发现上面的代码是有问题的：`dialog` 存在内存泄露

`dialog` 使用 `new` 在堆上分配空间，却一直没有 `delete`。解决方案也很简单：将 `MainWindow` 的指针赋给 `dialog` 即可

不过，这样做有一个问题：如果对话框不是在一个界面类中出现呢？由于 `QWidget` 的 `parent` 必须是 `QWidget` 指针，那就限制了我们不能将一个普通的 C++ 类指针传给 Qt 对话框。另外，如果对内存占用有严格限制的话，当主窗口作为 `parent` 时，主窗口不关闭，对话框就不会被销毁，所以会一直占用内存。在这种情景下，我们可以设置 `dialog` 的 `WindowAttribute`：

```cpp
QDialog *dialog = new QDialog;
dialog->setAttribute(Qt::WA_DeleteOnClose);
dialog->setWindowTitle(tr("Hello, dialog!"));
dialog->show();
```

`setAttribute()` 函数设置对话框关闭时，自动销毁对话框

---

## 消息对话框

`QMessageBox` 用于显示消息提示。我们一般会使用其提供的几个 `static` 函数：

* 显示关于对话框

```cpp
void about(QWidget * parent, const QString &title, const QString &text);
```

这是一个最简单的对话框，其标题是 `title`，内容是 `text`，父窗口是 `parent`。对话框只有一个 `OK` 按钮

* 显示关于 Qt 对话框。该对话框用于显示有关 Qt 的信息

```cpp
void aboutQt(QWidget * parent, const QString &title = QString());
```

* 显示严重错误对话框

```cpp
StandardButton critical(QWidget * parent, const QString &title, const QString &text, StandardButtons buttons = Ok, StandardButton defaultButton = NoButton);
```

这个对话框将显示一个红色的错误符号。我们可以通过 `buttons` 参数指明其显示的按钮。默认情况下只有一个 `Ok` 按钮，我们可以使用 `StandardButtons` 类型指定多种按钮

* 与 `QMessageBox::critical()` 类似，不同之处在于这个对话框提供一个普通信息图标

```cpp
StandardButton information(QWidget * parent, const QString &title, const QString &text, StandardButtons buttons = Ok, StandardButton defaultButton = NoButton);
```

* 与 `QMessageBox::critical()` 类似，不同之处在于这个对话框提供一个问号图标，并且其显示的按钮是 `是` 和 `否`

```cpp
StandardButton question(QWidget * parent, const QString &title, const QString &text, StandardButtons buttons = StandardButtons(Yes | No), StandardButton defaultButton = NoButton)
```

* 与 `QMessageBox::critical()` 类似，不同之处在于这个对话框提供一个黄色叹号图标

```cpp
StandardButton warning(QWidget * parent, const QString &title, const QString &text, StandardButtons buttons = Ok, StandardButton defaultButton = NoButton);
```

通过下面的代码来演示下如何使用 `QMessageBox`

```cpp
if (QMessageBox::Yes == QMessageBox::question(this,
              tr("Question"), tr("Are you OK?"),
              QMessageBox::Yes | QMessageBox::No,
              QMessageBox::Yes)) 
{
    QMessageBox::information(this, tr("Hmmm..."), tr("I'm glad to hear that!"));
} 
else 
{
    QMessageBox::information(this, tr("Hmmm..."), tr("I'm sorry!"));
}
```

使用 `QMessageBox::question()` 来询问一个问题。

* 这个对话框的父窗口是 `this`
* `QMessageBox`是 `QDialog` 的子类，这意味着它的初始显示位置将会是在 `parent` 窗口的中央
* 第二个参数是对话框的标题
* 第三个参数是我们想要显示的内容
* 第四个参数是关联的按键类型，我们可以使用或运算符 `(|)` 指定对话框应该出现的按钮。比如我们希望是一个 `Yes` 和一个 `No`
* 最后一个参数指定默认选择的按钮
    * 这个函数有一个返回值，用于确定用户点击的是哪一个按钮。按照我们的写法，应该很容易的看出，这是一个模态对话框，因此可以直接获取其返回值

`QMessageBox` 类的 `static` 函数优点是方便使用，缺点也很明显：非常不灵活

我们只能使用简单的几种形式。为了能够定制 `QMessageBox` 细节，我们必须使用 `QMessageBox` 的属性设置 API。如果我们希望制作一个询问是否保存的对话框，可以使用如下的代码：

```cpp
QMessageBox msgBox;
msgBox.setText(tr("The document has been modified."));
msgBox.setInformativeText(tr("Do you want to save your changes?"));
msgBox.setDetailedText(tr("Differences here..."));
msgBox.setStandardButtons(QMessageBox::Save
                          | QMessageBox::Discard
                          | QMessageBox::Cancel);
msgBox.setDefaultButton(QMessageBox::Save);
int ret = msgBox.exec();

switch (ret) 
{
case QMessageBox::Save:
    qDebug() << "Save document!";
    break;
case QMessageBox::Discard:
    qDebug() << "Discard changes!";
    break;
case QMessageBox::Cancel:
    qDebug() << "Close document!";
    break;
}
```

`msgBox` 是一个建立在栈上的 `QMessageBox` 实例。我们设置其主要文本信息为 `The document has been modified.`，`informativeText` 则是会在对话框中显示的简单说明文字

下面我们使用了一个 `detailedText`，也就是详细信息，当我们点击了详细信息按钮时，对话框可以自动显示更多信息。我们自己定义的对话框的按钮有三个：保存、丢弃和取消。然后我们使用了 `exec()` 是其成为一个模态对话框，根据其返回值进行相应的操作

上述所有操作的代码如下:

```cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenu>
#include <QAction>
#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 创建菜单栏，至多有一个
    QMenuBar *bar = menuBar();
    this->setMenuBar(bar);

    // 创建菜单
    QMenu *fileMenu = bar->addMenu("文件");
    //    QMenu *editMenu = bar->addMenu("编辑");
    //    QMenu *exitMenu = bar->addMenu("退出");

    // 创建菜单项
    QAction *newAction = fileMenu->addAction("新建");
    QAction *openAction = fileMenu->addAction("打开");

    // 添加分割线
    fileMenu->addSeparator();
    QAction *closeAction = fileMenu->addAction("关闭");

    // 点击新建，创建对话框
    //    this->connect(newAction,&QAction::triggered,this,[=](){
    //        // 对话框分类，模态对话框，非模态对话框
    //        // 模态对话框
    //        //        QDialog dlg(this);
    //        //        dlg.resize(120,50);
    //        //        // 阻塞
    //        //        dlg.exec();
    //        // 非模态对话框
    //        QDialog *dlg = new QDialog(this);
    //        dlg->resize(120,50);
    //        // 关闭对话框窗口不会消耗 dlg，只有关闭主窗口才会消耗
    //        dlg->show();
    //        // 可以设置 dlg 的 WindowAttribute
    //        dlg->setAttribute(Qt::WA_DeleteOnClose);
    //    });

    // QMessageBox 对话框
    // 错误对话框
    //    QMessageBox::critical(this,"错误","critical");

    // 信息提示对话框
    //    QMessageBox::information(this,"信息提示","info");

    // 询问提示对话框
    //    if(QMessageBox::Save == QMessageBox::question(this,"询问","question",QMessageBox::Save | QMessageBox::Cancel,QMessageBox::Cancel)){
    //        qDebug()<<"点击的是保存";
    //    }else{
    //        qDebug()<<"点击的是取消";
    //    }

    // 警告提示对话框
    //    QMessageBox::warning(this,"警告","warning");

    // 颜色对话框
    //    QColor color = QColorDialog::getColor(Qt::red);
    //    qDebug()<<color.red()<<color.green()<<color.blue();

    // 文件对话框
    //    QString fileName = QFileDialog::getOpenFileName(this,"打开文件","D:\\Wnow\\codes\\qt","(*.cpp)");
    //    qDebug()<<fileName;

    // 字体对话框
    bool flag;
    QFont font = QFontDialog::getFont(&flag,QFont("宋体",12));
    qDebug()<<"字体："<<font.family().toUtf8().data()<< "字号："<<font.pointSize()<<" 是否加粗："<<font.bold()<<" 是否倾斜："<<font.italic();

}

MainWindow::~MainWindow()
{
    delete ui;
}
```

---

## 标准文件对话框

`QFileDialog`，也就是文件对话框。本节将尝试编写一个简单的文本文件编辑器，我们将使用 `QFileDialog` 来打开一个文本文件，并将修改过的文件保存到硬盘

首先需要创建一个带有文本编辑功能的窗口：

```cpp
openAction = new QAction(QIcon(":/images/file-open"),tr("&Open..."), this);
openAction->setStatusTip(tr("Open an existing file"));
 
saveAction = new QAction(QIcon(":/images/file-save"), tr("&Save..."), this);
saveAction->setStatusTip(tr("Save a new file"));
 
QMenu *file = menuBar()->addMenu(tr("&File"));
file->addAction(openAction);
file->addAction(saveAction);
 
QToolBar *toolBar = addToolBar(tr("&File"));
toolBar->addAction(openAction);
toolBar->addAction(saveAction);
 
textEdit = new QTextEdit(this);
setCentralWidget(textEdit);
```

我们在菜单和工具栏添加了两个动作：打开和保存。接下来是一个 `QTextEdit` 类，这个类用于显示富文本文件。也就是说，它不仅仅用于显示文本，还可以显示图片、表格等等。不过，我们现在只用它显示纯文本文件

`QMainWindow` 有一个 `setCentralWidget()` 函数，可以将一个组件作为窗口的中心组件，放在窗口中央显示区。显然，在一个文本编辑器中，文本编辑区就是这个中心组件，因此我们将 `QTextEdit` 作为这种组件

我们使用 `connect()` 函数，为这两个 `QAction` 对象添加响应的动作：

```cpp
connect(openAction, &QAction::triggered, this, &MainWindow::openFile);
connect(saveAction, &QAction::triggered, this, &MainWindow::saveFile);
```

下面是最主要的 `openFile()` 和 `saveFile()` 这两个函数的代码：

```cpp
// 打开文件
void MainWindow::openFile()
{
    QString path = QFileDialog::getOpenFileName(this,
               tr("Open File"), ".", tr("Text Files(*.txt)"));
    if(!path.isEmpty()) 
    {
        QFile file(path);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) 
        {
            QMessageBox::warning(this, tr("Read File"),
                         tr("Cannot open file:\n%1").arg(path));
            return;
        }
        QTextStream in(&file);
        textEdit->setText(in.readAll());
        file.close();
    } 
    else 
    {
        QMessageBox::warning(this, tr("Path"),
                             tr("You did not select any file."));
    }
}
 
// 保存文件
void MainWindow::saveFile()
{
    QString path = QFileDialog::getSaveFileName(this,
               tr("Open File"), ".", tr("Text Files(*.txt)"));
    if(!path.isEmpty()) 
    {
        QFile file(path);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) 
        {
            QMessageBox::warning(this, tr("Write File"),
                         tr("Cannot open file:\n%1").arg(path));
            return;
        }
        QTextStream out(&file);
        out << textEdit->toPlainText();
        file.close();
    } 
    else 
    {
        QMessageBox::warning(this, tr("Path"),
                             tr("You did not select any file."));
    }
}
```

在 `openFile()` 函数中，我们使用 `QFileDialog::getOpenFileName()` 来获取需要打开的文件的路径。这个函数原型如下：

```cpp
QString getOpenFileName(QWidget * parent = 0, const QString &caption = QString(), const QString &dir = QString(), const QString &filter = QString(), QString * selectedFilter = 0, Options options = 0);
```

不过注意，它的所有参数都是可选的，因此在一定程度上说，这个函数也是简单的。这六个参数分别是：

* `parent`：父窗口。Qt 的标准对话框提供静态函数，用于返回一个模态对话框
* `caption`：对话框标题；
* `dir`：对话框打开时的默认目录
    * `.` 代表程序运行目录
    * `/` 代表当前盘符的根目录(特指 Windows 平台；Linux 平台当然就是根目录)，这个参数也可以是平台相关的，比如 `C:\\` 等
* `filter`：过滤器
    * 我们使用文件对话框可以浏览很多类型的文件，但是，很多时候仅希望打开特定类型的文件。比如，文本编辑器希望打开文本文件，图片浏览器希望打开图片文件。过滤器就是用于过滤特定的后缀名。如果我们使用 `Image Files(*.jpg *.png)`，则只能显示后缀名是 `jpg` 或者 `png` 的文件。如果需要多个过滤器，使用 `;;` 分割，比如 `JPEG Files(*.jpg);;PNG Files(*.png)`
* `selectedFilter`：默认选择的过滤器
* `options`：对话框的一些参数设定
    * 比如只显示文件夹等等，它的取值是 `enum QFileDialog::Option`，每个选项可以使用 `|` 运算组合起来。

`QFileDialog::getOpenFileName()` 返回值是选择的文件路径。我们将其赋值给 `path`。通过判断 `path` 是否为空，可以确定用户是否选择了某一文件。只有当用户选择了一个文件时，才执行下面的操作

在 `saveFile()` 中使用的 `QFileDialog::getSaveFileName()` 也是类似的。使用这种静态函数，在 Windows、Mac OS 上面都是直接调用本地对话框，但是 Linux 上则是 `QFileDialog` 自己模拟

这暗示了，如果你不使用这些静态函数，而是直接使用 `QFileDialog` 进行设置，那么得到的对话框很可能与系统对话框的外观不一致。这一点是需要注意的

---
