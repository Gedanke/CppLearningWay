# Linux 操作入门

---

## 简介

操作系统在计算机系统中承上启下的地位：向下封装硬件，向上提供操作接口

![](../photos/part12/1.png)

Linux 具有如下的优秀的特点：

* 开放性
* 完全免费
* 多用户
* 多任务
* 良好的用户界面
* 设备独立性
* 提供了丰富的网络功能
* 可靠的系统安全性
* 良好的可移植性

X Window 系统是一个非常出色的图形窗口系统，是类UNIX系统的图形用户界面的工业标准。X Window系统最重要的特征之一就是它的结构与设备无关

X Window 系统的主要特点有如下几点：

* X Window系统是客户机/服务器结构的。X Window 的实现是与操作系统内核分开的，其主要由 X Server 和 X Client 两部分组成
* X Window 系统不是 Unix/Linux 操作系统的必须的构成部分，而只是一个可选的应用程序组件

---

## 文件系统

### 目录和路径

#### 目录

* 目录是一组相关文件的集合
* 一个目录下面除了可以存放文件之外还可以存放其他目录，即可包含子目录
* 在确定文件、目录位置时，DOS 和 Unix/Linux 都采用 `路径名+文件名` 的方式。路径反映的是目录与目录之间的关系

#### 路径

Unix/Linux 路径由到达定位文件的目录组成。在 Unix/Linux 系统中组成路径的目录分割符为斜杠 `/`，而 DOS 则用反斜杠 `\` 来分割各个目录

路径分为绝对路径和相对路径：

* 绝对路径
    * 绝对路径是从目录树的树根 `/` 目录开始往下直至到达文件所经过的所有节点目录
    * 下级目录接在上级目录后面用 `/` 隔开
    * 注意：绝对路径都是从 `/` 开始的，所以第一个字符一定是 `/`
* 相对路径
    * 相对路径是指目标目录相对于当前目录的位置
    * 如果不在当前目录下，则需要使用两个特殊目录 `.` 和 `..` 了。目录 `.` 指向当前目录，而目录 `..` 指向上一级目录

### 文件系统

#### Windows 和 Linux 文件系统区别

在 windows 平台下，打开“计算机”，看到的是一个个的驱动器盘符，每个驱动器都有自己的根目录结构，这样形成了多个树并列的情形

在 Linux 下，我们是看不到这些驱动器盘符，看到的是文件夹(目录)

1994 年，Linux 对根文件目录做了统一的规范，推出 FHS(Filesystem Hierarchy Standard)的 Linux 文件系统层次结构标准。FHS 标准规定了 Linux 根目录各文件夹的名称及作用，统一了 Linux 界命名混乱的局面

和 Windows 操作系统类似，所有 Unix/Linux 的数据都是由文件系统按照树型目录结构管理的。而且 Unix/Linux 操作系统同样要区分文件的类型，判断文件的存取属性和可执行属性

Unix/Linux 也采用了树状结构的文件系统，它由目录和目录下的文件一起构成。但 Unix/Linux 文件系统不使用驱动器这个概念，而是使用单一的根目录结构，所有的分区都挂载到单一的 `/` 目录上，其结构示意图如图所示

![](../photos/part12/2.png)

#### Linux 目录结构

* `/`：根目录，一般根目录下只存放目录，在 Linux 下有且只有一个根目录。所有的东西都是从这里开始
* `/bin`: `/usr/bin`: 可执行二进制文件的目录，如常用的命令 `ls、tar、mv、cat` 等
* `/boot`：放置 linux 系统启动时用到的一些文件，如 Linux 的内核文件：`/boot/vmlinuz`，系统引导管理器：`/boot/grub`
* `/dev`：存放 linux 系统下的设备文件，访问该目录下某个文件，相当于访问某个设备，常用的是挂载光驱 `mount /dev/cdrom /mnt`
* `/etc`：系统配置文件存放的目录，不建议在此目录下存放可执行文件，重要的配置文件有 `/etc/inittab、/etc/fstab、/etc/init.d、/etc/X11、/etc/sysconfig、/etc/xinetd.d`
* `/home`：系统默认的用户家目录，新增用户账号时，用户的家目录都存放在此目录下，`~` 表示当前用户的家目录，`~edu` 表示用户 `edu` 的家目录
* `/lib`: `/usr/lib、/usr/local/lib`：系统使用的函数库的目录，程序在执行过程中，需要调用一些额外的参数时需要函数库的协助
* `/lost+fount`：系统异常产生错误时，会将一些遗失的片段放置于此目录下
* `/mnt`: `/media`：光盘默认挂载点，通常光盘挂载于 `/mnt/cdrom` 下，也不一定，可以选择任意位置进行挂载
* `/opt`：给主机额外安装软件所摆放的目录
* `/proc`：此目录的数据都在内存中，如系统核心，外部设备，网络状态，由于数据都存放于内存中，所以不占用磁盘空间，比较重要的目录有 `/proc/cpuinfo、/proc/interrupts、/proc/dma、/proc/ioports、/proc/net/*` 等
* `/root`：系统管理员 `root` 的家目录
* `/sbin`: `/usr/sbin、/usr/local/sbin`：放置系统管理员使用的可执行命令，如 `fdisk、shutdown、mount` 等。与 `/bin` 不同的是，这几个目录是给系统管理员 `root` 使用的命令，一般用户只能"查看"而不能设置和使用
* `/tmp`：一般用户或正在执行的程序临时存放文件的目录，任何人都可以访问，重要数据不可放置在此目录下
* `/srv`：服务启动之后需要访问的数据目录，如 `www` 服务需要访问的网页数据存放在 `/srv/www` 内
* `/usr`：应用程序存放目录，`/usr/bin` 存放应用程序，`/usr/share` 存放共享数据，`/usr/lib` 存放不能直接运行的，却是许多程序运行所必需的一些函数库文件。`/usr/local`: 存放软件升级包。`/usr/share/doc`: 系统说明文件存放目录。`/usr/share/man`:  程序说明文件存放目录
* `/var`：放置系统执行过程中经常变化的文件，如随时更改的日志文件 `/var/log`、`/var/log/message`：所有的登录文件存放目录，`/var/spool/mail`：邮件存放的目录，`/var/run`：程序或服务启动后，其 `PID` 存放在该目录下

### 一切皆文件

Unix/Linux 对数据文件(`*.mp3、*.bmp`)，程序文件(`*.c、*.h、*.o`)，设备文件(LCD、触摸屏、鼠标)，网络文件(`socket`)等的管理都抽象为文件，使用统一的方式方法管理

在 Unix/Linux 操作系统中也必须区分文件类型，通过文件类型可以判断文件属于可执行文件、文本文件还是数据文件。在 Unix/Linux 系统中文件可以没有扩展名

#### 文件分类

通常，Unix/Linux 系统中常用的文件类型有5种：普通文件、目录文件、设备文件、管道文件和链接文件

* 普通文件

普通文件是计算机操作系统用于存放数据、程序等信息的文件，一般都长期存放于外存储器(磁盘、磁带等)中。普通文件一般包括文本文件、数据文件、可执行的二进制程序文件等

在 Unix/Linux 中可以通过 `file` 命令来查看文件的类型。如果 `file` 文件后面携带文件名，则查看指定文件的类型，如果携带通配符 `*`，则可以查看当前目录下的所有文件的类型

```sh
# file main.c
main.c: C source, ASCII text
# file *
main:   ELF 64-bit LSB shared object, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, BuildID[sha1]=54498620e30acd9275a1cac8bcaeb95e97953889, for GNU/Linux 3.2.0, not stripped
main.c: C source, ASCII text
# 
```

* 目录文件

Unix/Linux 系统把目录看成是一种特殊的文件，利用它构成文件系统的树型结构

目录文件只允许系统管理员对其进行修改，用户进程可以读取目录文件，但不能对它们进行修改

每个目录文件至少包括两个条目，`..` 表示上一级目录，`.` 表示该目录本身

```sh
# ls -al
total 32
drwxr-xr-x 2 root root  4096 Aug  3 20:10 .
drwxr-xr-x 5 root root  4096 Aug  1 10:43 ..
-rwxr-xr-x 1 root root 17240 Aug  3 16:31 main
-rw-r--r-- 1 root root    50 Aug  3 20:10 main.c
# 
```

* 设备文件

Unix/Linux 系统把每个设备都映射成一个文件，这就是设备文件。它是用于向 I/O 设备提供连接的一种文件，分为字符设备和块设备文件

字符设备的存取以一个字符为单位，块设备的存取以字符块为单位。每一种 I/O 设备对应一个设备文件，存放在 `/dev` 目录中，如行式打印机对应 `/dev/lp`，第一个软盘驱动器对应 `/dev/fd0`

```sh
# lsblk
NAME   MAJ:MIN RM SIZE RO TYPE MOUNTPOINT
vda    252:0    0  40G  0 disk 
└─vda1 252:1    0  40G  0 part /
#
```

* 管道文件

管道文件也是 Unix/Linux 中较特殊的文件类型，这类文件多用于进程间的通信

* 链接文件

似于 windows 下的快捷方式，链接又可以分为软链接(符号链接)和硬链接

### 文件权限

文件权限就是文件的访问控制权限，即哪些用户和组群可以访问文件以及可以执行什么样的操作

Unix/Linux 系统是一个典型的多用户系统，不同的用户处于不同的地位，对文件和目录有不同的访问权限。为了保护系统的安全性，Unix/Linux 系统除了对用户权限作了严格的界定外，还在用户身份认证、访问控制、传输安全、文件读写权限等方面作了周密的控制

在 Unix/Linux 中的每一个文件或目录都包含有访问权限，这些访问权限决定了谁能访问和如何访问这些文件和目录

#### 访问用户

通过设定权限可以从以下三种访问方式限制访问权限：

* 只允许用户自己访问(所有者)

所有者就是创建文件的用户，用户是所有用户所创建文件的所有者，用户可以允许所在的用户组能访问用户的文件

* 允许一个预先指定的用户组中的用户访问(用户组)

用户都组合成用户组，例如，某一类或某一项目中的所有用户都能够被系统管理员归为一个用户组，一个用户能够授予所在用户组的其他成员的文件访问权限

* 允许系统中的任何用户访问(其他用户)

用户也将自己的文件向系统内的所有用户开放，在这种情况下，系统内的所有用户都能够访问用户的目录或文件。在这种意义上，系统内的其他所有用户就是 `other` 用户类

#### 访问权限

用户能够控制一个给定的文件或目录的访问程度，一个文件或目录可能有读、写及执行权限：

* 读权限 `r`。对文件而言，具有读取文件内容的权限；对目录来说，具有浏览目录的权限
* 写权限 `w`。对文件而言，具有新增、修改文件内容的权限；对目录来说，具有删除、移动目录内文件的权限
* 可执行权限 `x`。对文件而言，具有执行文件的权限；对目录了来说该用户具有进入目录的权限

Unix/Linux 系统只允许文件的属主(所有者)或超级用户改变文件的读写权限

#### 示例说明

```sh
# ls -lh
total 24K
-rwxr-xr-x 1 root root 17K Aug  3 16:31 main
-rw-r--r-- 1 root root  50 Aug  3 20:10 main.c
# 
```

![](../photos/part12/3.png)

* 第 1 个字母代表文件的类型：`d` 代表文件夹、`-` 代表普通文件、`c` 代表硬件字符设备、`b` 代表硬件块设备、`s` 表示管道文件、`l` 代表软链接文件
* 后 9 个字母分别代表三组权限：文件所有者、用户者、其他用户拥有的权限。每一个用户都有它自身的读、写和执行权限
    * 第一组权限控制访问自己的文件权限，即文件所有者权限
    * 第二组权限控制用户组访问其中一个用户的文件的权限
    * 第三组权限控制其他所有用户访问一个用户的文件的权限

这三组权限赋予用户不同类型(即所有者、用户组和其他用户)的读、写及执行权限就构成了一个有 9 种类型的权限组

---

## 常用命令

### 命令使用方法

#### Linux 命令格式

```sh
command [-options] [parameter1] ...
```
说明：

* `command`：命令名，相应功能的英文单词或单词的缩写
* `[-options]`：选项，可用来对命令进行控制，也可以省略，`[]` 代表可选
* `[parameter1] ...`：传给命令的参数，可以是零个一个或多个

```sh
# ls -a /home/root/
.  ..  codes  download  p.txt  sources  .swp  test
#
```

#### 查看帮助文档

* `--help`

一般是 Linux 命令自带的帮助信息，并不是所有命令都自带这个选项

如想查看命令 `ls` 的用法：`ls --help`

```sh
# ls --help
Usage: ls [OPTION]... [FILE]...
List information about the FILEs (the current directory by default).
Sort entries alphabetically if none of -cftuvSUX nor --sort is specified.

Mandatory arguments to long options are mandatory for short options too.
  -a, --all                  do not ignore entries starting with .
  -A, --almost-all           do not list implied . and ..
      --author               with -l, print the author of each file
  -b, --escape               print C-style escapes for nongraphic characters
      --block-size=SIZE      with -l, scale sizes by SIZE when printing them;
                               e.g., '--block-size=M'; see SIZE format below
  -B, --ignore-backups       do not list implied entries ending with ~
  -c                         with -lt: sort by, and show, ctime (time of last
                               modification of file status information);
                               with -l: show ctime and sort by name;
                               otherwise: sort by ctime, newest first
...
```

* `man`

`man` 是 Linux 提供的一个手册，包含了绝大部分的命令、函数使用说明

该手册分成很多章节(section)，使用 `man` 时可以指定不同的章节来浏览不同的内容

`man` 中各个 section 意义如下：

* Standard commands(标准命令)
* System calls(系统调用，如 `open，write`)
* Library functions(库函数，如 `printf，fopen`)
* Special devices(设备文件的说明，`/dev` 下各种设备）
* File formats(文件格式，如 passwd)
* Games and toys(游戏和娱乐)
* Miscellaneous(杂项、惯例与协定等，例如 Linux 档案系统、网络协定、ASCII 码；`environ`全局变量)
* Administrative Commands(管理员命令，如 `ifconfig`)

`man` 使用格式如下：

```sh
man [选项] 命令名
```

`man` 设置了如下的功能键：

| 功能键 | 功能 |
|:----:|:----:|
| 空格键 | 显示手册页的下一屏 |
| Enter 键 | 一次滚动手册页的一行 |
| `b` | 回滚一屏 |
| `f` | 前滚一屏 |
| `q` | 退出 `man` 命令 |
| `h` | 列出所有功能键 |
| `/word` | 搜索 `word` 字符串 |

如想查看 `ls` 的用法：`man 1 ls` (1：为数字“1”，代表第 1 个 section，标准命令)

```sh
# man 1 ls
LS(1)                                                                                                           User Commands                                                                                                           LS(1)

NAME
       ls - list directory contents

SYNOPSIS
       ls [OPTION]... [FILE]...

DESCRIPTION
       List information about the FILEs (the current directory by default).  Sort entries alphabetically if none of -cftuvSUX nor --sort is specified.

       Mandatory arguments to long options are mandatory for short options too.

       -a, --all
              do not ignore entries starting with .

       -A, --almost-all
              do not list implied . and ..

       --author
              with -l, print the author of each file
 Manual page ls(1) line 1 (press h for help or q to quit)
```

实际上不指定第几个章节也用查看，如，`man ls`

但是，有一种情况，假如，命令的名字和函数的名字刚好重名(如：`printf`)，它既是命令，也可以是库函数，如果不指定章节号，`man printf`，它只查看命令的用法，不会查询函数的用法，因为 `man` 是按照手册的章节号的顺序进行搜索的

```sh
# man printf
PRINTF(1)                                                                                                       User Commands                                                                                                       PRINTF(1)

NAME
       printf - format and print data

SYNOPSIS
       printf FORMAT [ARGUMENT]...
       printf OPTION

DESCRIPTION
       Print ARGUMENT(s) according to FORMAT, or execute according to OPTION:

       --help display this help and exit

       --version
              output version information and exit

       FORMAT controls the output as in C printf.  Interpreted sequences are:

       \"     double quote

 Manual page printf(1) line 1 (press h for help or q to quit)
```

`PRINTF(1)` 1，代表标准命令

所以，使用 `man` 手册时，最好指定章节号

```sh
# man 3 printf
PRINTF(3)                                                                                                 Linux Programmer's Manual                                                                                                 PRINTF(3)

NAME
       printf, fprintf, dprintf, sprintf, snprintf, vprintf, vfprintf, vdprintf, vsprintf, vsnprintf - formatted output conversion

SYNOPSIS
       #include <stdio.h>

       int printf(const char *format, ...);
       int fprintf(FILE *stream, const char *format, ...);
       int dprintf(int fd, const char *format, ...);
       int sprintf(char *str, const char *format, ...);
       int snprintf(char *str, size_t size, const char *format, ...);

       #include <stdarg.h>

       int vprintf(const char *format, va_list ap);
       int vfprintf(FILE *stream, const char *format, va_list ap);
       int vdprintf(int fd, const char *format, va_list ap);
       int vsprintf(char *str, const char *format, va_list ap);
       int vsnprintf(char *str, size_t size, const char *format, va_list ap);
 Manual page printf(3) line 1 (press h for help or q to quit)
```

### 使用技巧

* 自动补全

在敲出命令的前几个字母的同时，按下 `tab` 键，系统会自动帮我们补全命令

* 历史命令

当系统执行过一些命令后，可按上下键翻看以前的命令，`history` 将执行过的命令列举出来

### 常用命令

#### 文件管理

* 查看文件信息：`ls`

`ls` 是英文单词 list 的简写，其功能为列出目录的内容，是用户最常用的命令之一，它类似于 DOS 下的 `dir` 命令

Linux 文件或者目录名称最长可以有 256 个字符，以 `.` 开头的文件为隐藏文件，需要用 `-a` 参数才能显示

`ls` 常用参数：

| 参数 | 含义 |
|:----:|:----:|
| `-a` | 显示指定目录下所有子目录与文件，包括隐藏文件 |
| `-l` | 以列表方式显示文件的详细信息 |
| `-h` | 配合 `-l` 以人性化的方式显示文件大小 |

```sh
# ls
main  main.c
# ls -a
.  ..  main  main.c
# ls -lh
total 24K
-rwxr-xr-x 1 root root 17K Aug  3 16:31 main
-rw-r--r-- 1 root root  50 Aug  3 20:10 main.c
#
```

图中列出的信息含义如下图所示

![](../photos/part12/4.png)

与 DOS 下的文件操作类似，在 Unix/Linux 系统中，也同样允许使用特殊字符来同时引用多个文件名，这些特殊字符被称为通配符

| 通配符 | 含义 |
|:----:|:----:|
| `*` | 文件代表文件名中所有字符 |
| `ls te*` | 查找以 `te` 开头的文件 |
| `ls *html` | 查找结尾为 `html` 的文件 |
| `?` | 代表文件名中任意一个字符 |
| `ls ?.c` | 只找第一个字符任意，后缀为 `.c` 的文件 |
| `ls a.?` | 只找只有 3 个字符，前 2 字符为 `a.`，最后一个字符任意的文件 |
| `[]` | `[` 和 `]` 将字符组括起来，表示可以匹配字符组中的任意一个。`-` 用于表示字符范围 |
| `[abc]` | 匹配 `a、b、c` 中的任意一个 |
| `[a-f]` | 匹配从 `a` 到 `f` 范围内的的任意一个字符 |
| `ls [a-f]*` | 找到从 `a` 到 `f` 范围内的的任意一个字符开头的文件 |
| `ls a-f` | 查找文件名为 `a-f` 的文件，当 `-` 处于方括号之外失去通配符的作用 |
| `\` | 如果要使通配符作为普通字符使用，可以在其前面加上转义字符。`?` 和 `*` 处于方括号内时不用使用转义字符就失去通配符的作用
| `ls \*a` | 查找文件名为 `*a` 的文件 |

* 输出重定向命令：`>`

Linux 允许将命令执行结果重定向到一个文件，本应显示在终端上的内容保存到指定文件中

如：`ls > test.txt` (`test.txt` 如果不存在，则创建，存在则覆盖其内容)

```sh
# ls
demo.txt
# ls > test1.txt
# ls
demo.txt  test1.txt
# cat test1.txt
demo.txt
test1.txt
# touch test2.txt
# ls
demo.txt  test1.txt  test2.txt
# cat test1.txt
demo.txt
test1.txt
# ls > test1.txt
# cat test1.txt
demo.txt
test1.txt
test2.txt
#
```

`>` 输出重定向会覆盖原来的内容，`>>` 输出重定向则会追加到文件的尾部

* 分屏显示：`more`

查看内容时，在信息过长无法在一屏上显示时，会出现快速滚屏，使得用户无法看清文件的内容，此时可以使用 `more` 命令，每次只显示一页，按下空格键可以显示下一页，按下 `q` 键退出显示，按下 `h` 键可以获取帮助

```sh
# man 1 printf | more
PRINTF(1)                                           User Commands                                           PRINTF(1)

NAME
       printf - format and print data

SYNOPSIS
       printf FORMAT [ARGUMENT]...
       printf OPTION

DESCRIPTION
       Print ARGUMENT(s) according to FORMAT, or execute according to OPTION:

       --help display this help and exit

       --version
              output version information and exit

       FORMAT controls the output as in C printf.  Interpreted sequences are:

       \"     double quote

       \\     backslash

       \a     alert (BEL)

       \b     backspace

       \c     produce no further output

--More--
```

* 管道：`|`

管道：一个命令的输出可以通过管道做为另一个命令的输入，`|` 的左右分为两端，左端塞东西(写)，右端取东西(读)

```sh
# ls -alh | more
total 12K
drwxr-xr-x 2 root root 4.0K Aug  3 22:21 .
drwxr-xr-x 6 root root 4.0K Jan 19  2022 ..
-rw-r--r-- 1 root root    0 Aug  3 22:19 demo.txt
-rw-r--r-- 1 root root   29 Aug  3 22:22 test1.txt
-rw-r--r-- 1 root root    0 Aug  3 22:21 test2.txt
#
```









---
