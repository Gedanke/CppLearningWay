#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ConfigInfo
{
    char key[64];
    char value[64];
} ConfigInfo;

// 当前行是否为有效行
int isValidLine(char *buf)
{
    // 行没有结束符号 0 或者 \0，或者没有 :，则不是有效行
    if (buf[0] == '0' || buf[0] == '\0' || strchr(buf, ':') == NULL)
    {
        return 0;
    }
    return 1;
}

// 获取文件有效行数
int getFileLine(const char *filePath)
{
    FILE *file = fopen(filePath, "r");
    int num = 0;
    char buf[130] = {0};

    while (fgets(buf, 130, file) != NULL)
    {
        if (isValidLine(buf))
        {
            num++;
        }
        memset(buf, 0, 130);
    }
    fclose(file);
    file = NULL;

    return num;
}

void parseFile(const char *filePath, int lines, ConfigInfo **config)
{
    ConfigInfo *pConfig = (ConfigInfo *)malloc(sizeof(ConfigInfo) * lines);
    if (pConfig == NULL)
    {
        return;
    }

    FILE *file = fopen(filePath, "r");
    char buf[130] = {0};

    int idx = 0;
    while (fgets(buf, 130, file) != NULL)
    {
        if (isValidLine(buf))
        {
            // 有效行进行数据解析
            memset(pConfig[idx].key, 0, 64);
            memset(pConfig[idx].value, 0, 64);

            // 以 : 进行分割
            char *pos = strchr(buf, ':');
            // buf 开始，长度是 pos - buf
            strncpy(pConfig[idx].key, buf, pos - buf);
            // pos + 1 开始，长度是 pos + 1 字符串长度 - 1，1 是换行符
            strncpy(pConfig[idx].value, pos + 1, strlen(pos + 1) - 1);
            idx++;
        }
        memset(buf, 0, 130);
    }

    *config = pConfig;
}

// 获取指定信息配置
char *getInfoByKey(char *key, ConfigInfo *configInfo, int lines)
{
    for (int i = 0; i < lines; i++)
    {
        if (strcmp(key, configInfo[i].key) == 0)
        {
            return configInfo[i].value;
        }
    }
    return NULL;
}

// 释放内存
void freeConfigInfo(ConfigInfo *configInfo)
{
    free(configInfo);
    configInfo = NULL;
}

void test()
{
    char *filePath = "./config.txt";
    int lines = getFileLine(filePath);
    printf("文件的有效行数是：%d\n", lines);

    ConfigInfo *config = NULL;
    parseFile(filePath, lines, &config);

    printf("heroId = %s\n", getInfoByKey("heroId", config, lines));
    printf("heroName: = %s\n", getInfoByKey("heroName", config, lines));
    printf("heroAtk = %s\n", getInfoByKey("heroAtk", config, lines));
    printf("heroDef: = %s\n", getInfoByKey("heroDef", config, lines));
    printf("heroInfo: = %s\n", getInfoByKey("heroInfo", config, lines));

    freeConfigInfo(config);
    config = NULL;
}

int main()
{
    test();

    /*
        文件的有效行数是：5
        heroId = 1
        heroName: = 德玛西亚
        heroAtk = 1000
        heroDef: = 500
        heroInfo: = 前排坦克
     */

    return 0;
}