#include <stdio.h>
#include <stdlib.h>
#define OS_FLAG "Windows" //填写Windows,Linux或UNIX
#define VERSION "1.0"
void system_plus(const char *command); //基于system函数,但是加了命令是否执行成功判断
void clearscreen(void); //清屏
void safe_flush(FILE *fp); //清除stdin函数(抄的)
void checkkr(void); //检查扩容
int checkfile(char *filename); //检查文件是否存在
int main(void)
{
    int choose;
    if (OS_FLAG != "Windows" && OS_FLAG != "Linux" && OS_FLAG != "UNIX")
    {
        printf("预处理器指令填写错误!清修改后重新编译本程序!\n");
        printf("按回车键退出程序");
        getchar();
        exit(0);
    }
    printf("检查文件...\n");
    if (OS_FLAG == "Windows")
    {
        checkfile("bin\\adb.exe");
	    checkfile("bin\\AdbWinApi.dll");
	    checkfile("bin\\AdbWinUsbApi.dll");
	    checkfile("bin\\fastboot.exe");
    }
    else
    {
        checkfile("bin/adb");
	    checkfile("bin/fastboot");
    }
    printf("启动ADB服务...\n");
    if (OS_FLAG == "Windows")
        system("taskkill /f /im adb.exe");
    else
        system("killall adb");
    system_plus("bin/adb start-server");
    while (1)
    {
        clearscreen();
        printf("=--------------R11/s一键刷机工具By WenHao---------=\n");
        printf("\n");
        printf("               Version %s\n", VERSION);
        printf("\n");
        printf(" 欢迎使用本一键工具，未经允许禁止商用\n");
        printf(" 未经允许禁止用于付费远程\n");
        printf(" 举报方式:email: CY@cyteam.cn\n");
        printf("                 CZ@cyteam.cn\n");
        printf(" 感谢您的支持，谢谢\n");
        printf("\n");
        printf(" 1.一键刷入当前ROM\n");
        printf("\n");
        printf(" 2.访问下载站以获取更多资源\n");
        printf("\n");
        printf("=------------------------------------------------=\n");
        printf("请输入你想要使用的功能序号:");
        if (scanf("%d", &choose) == 1)
        {
            safe_flush(stdin); //清除stdin
            clearscreen();
            switch(choose)
            {
                case 1:
                    checkkr();
                    printf("请将手机进入Fastboot模式。正在等待设备连接...\n");
                    printf("准备写入底层...\n");
                    if (OS_FLAG == "Windows")
                    {
                        system_plus("bin\\fastboot flash bluetooth firmware-update\\bluetooth.img");
                        system_plus("bin\\fastboot flash tz firmware-update\\tz.img");
                        system_plus("bin\\fastboot flash cmnlib firmware-update\\cmnlib.img");
                        system_plus("bin\\fastboot flash cmnlib64 firmware-update\\cmnlib64.img");
                        system_plus("bin\\fastboot flash devcfg firmware-update\\devcfg.img");
                        system_plus("bin\\fastboot flash apdp firmware-update\\dpAP.img");
                        system_plus("bin\\fastboot flash msadp firmware-update\\dpMSA.img");
                        system_plus("bin\\fastboot flash DRIVER firmware-update\\DRIVER.img");
                        system_plus("bin\\fastboot flash dsp firmware-update\\dsp.img");
                        system_plus("bin\\fastboot flash hyp firmware-update\\hyp.img");
                        system_plus("bin\\fastboot flash keymaster firmware-update\\keymaster.img");
                        system_plus("bin\\fastboot flash LOGO firmware-update\\logo.img");
                        system_plus("bin\\fastboot flash abl firmware-update\\abl.img");
                        system_plus("bin\\fastboot flash mdtp firmware-update\\mdtp.img");
                        system_plus("bin\\fastboot flash mdtpsecapp firmware-update\\mdtpsecapp.img");
                        system_plus("bin\\fastboot flash pmic firmware-update\\pmic.img");
                        system_plus("bin\\fastboot flash xbl firmware-update\\xbl.img");
                        system_plus("bin\\fastboot flash rpm firmware-update\\rpm.img");
                        system_plus("bin\\fastboot flash splash firmware-update\\splash.img");
                        system_plus("bin\\fastboot flash oppostanvbk firmware-update\\static_nvbk.img");
                        system_plus("bin\\fastboot flash misc firmware-update\\misc.img");
                        system_plus("bin\\fastboot flash modem firmware-update\\modem.img");
                        system_plus("bin\\fastboot flash recovery firmware-update\\recovery.img");
                    }
                    else
                    {
                        system_plus("bin/fastboot flash bluetooth firmware-update/bluetooth.img");
                        system_plus("bin/fastboot flash tz firmware-update/tz.img");
                        system_plus("bin/fastboot flash cmnlib firmware-update/cmnlib.img");
                        system_plus("bin/fastboot flash cmnlib64 firmware-update/cmnlib64.img");
                        system_plus("bin/fastboot flash devcfg firmware-update/devcfg.img");
                        system_plus("bin/fastboot flash apdp firmware-update/dpAP.img");
                        system_plus("bin/fastboot flash msadp firmware-update/dpMSA.img");
                        system_plus("bin/fastboot flash DRIVER firmware-update/DRIVER.img");
                        system_plus("bin/fastboot flash dsp firmware-update/dsp.img");
                        system_plus("bin/fastboot flash hyp firmware-update/hyp.img");
                        system_plus("bin/fastboot flash keymaster firmware-update/keymaster.img");
                        system_plus("bin/fastboot flash LOGO firmware-update/logo.img");
                        system_plus("bin/fastboot flash abl firmware-update/abl.img");
                        system_plus("bin/fastboot flash mdtp firmware-update/mdtp.img");
                        system_plus("bin/fastboot flash mdtpsecapp firmware-update/mdtpsecapp.img");
                        system_plus("bin/fastboot flash pmic firmware-update/pmic.img");
                        system_plus("bin/fastboot flash xbl firmware-update/xbl.img");
                        system_plus("bin/fastboot flash rpm firmware-update/rpm.img");
                        system_plus("bin/fastboot flash splash firmware-update/splash.img");
                        system_plus("bin/fastboot flash oppostanvbk firmware-update/static_nvbk.img");
                        system_plus("bin/fastboot flash misc firmware-update/misc.img");
                        system_plus("bin/fastboot flash modem firmware-update/modem.img");
                        system_plus("bin/fastboot flash recovery firmware-update/recovery.img");
                    }
                    printf("正在写入boot...\n");
                    if (OS_FLAG == "Windows")
                    {
                        system_plus("bin\\fastboot flash boot boot.img");
                    }
                    else
                    {
                        system_plus("bin/fastboot flash boot boot.img");
                    }
                    printf("正在写入system...\n");
                    printf("温馨提示：当前文件较大，可能消耗一定的时间\n");
                    if (OS_FLAG == "Windows")
                    {
                        system_plus("bin\\fastboot flash system system.img");
                    }
                    else
                    {
                        system_plus("bin/fastboot flash system system.img");
                    }
                    printf("正在写入vendor...\n");
                    if (OS_FLAG == "Windows")
                    {
                        system_plus("bin\\fastboot flash vendor vendor.img");
                    }
                    else
                    {
                        system_plus("bin/fastboot flash vendor vendor.img");
                    }
                    printf("恭喜刷入成功,即将进入Recovery模式,完成优化...\n");
                    if (OS_FLAG == "Windows")
                        system_plus("bin\\fastboot reboot");
                    else
                        system_plus("bin/fastboot reboot");
                    printf("正在等待Recovery连接...\n");
                    if (OS_FLAG == "Windows")
                    {
                        system_plus("bin\\adb wait-for-recovery devices");
                        system_plus("bin\\adb shell twrp format data");
                        system_plus("bin\\adb shell twrp wipe cache");
                    }
                    else
                    {
                        system_plus("bin/adb wait-for-recovery devices");
                        system_plus("bin/adb shell twrp format data");
                        system_plus("bin/adb shell twrp wipe cache");
                    }
                    printf("刷机完成，正在开机...\n");
                    printf("执行完毕，按回车键回到主页...");
                    getchar();
                case 2:
                    if (OS_FLAG == "Windows")
                    {
                        printf("正在打开下载站，请稍等...\n");
                        system("start https://cheng.xz.cn");
                        printf("如果无法打开您也可以手动访问以下任何一个地址\n");
                        printf("地址：https://d.cyteam.cn\n");
                        printf("      https://cheng.xz.cn\n");
                        printf("按回车键返回主菜单");
                        getchar();
                        continue;
                    }
                    else
                    {
                        printf("暂不支持此操作系统,清手动打开!\n");
                        printf("地址：https://d.cyteam.cn\n");
                        printf("      https://cheng.xz.cn\n");
                        printf("按回车键返回主菜单");
                        getchar();
                        continue;
                    }
                default:
                    printf("输入有误,请重试!");
                    getchar();
                    continue;
            }
        }
        else
        {
            safe_flush(stdin); //清除stdin
            printf("输入有误,请重试!");
            getchar();
            continue;
        }

    }
}
void system_plus(const char *command)
{
    char choose;
    if (system(command) != 0)
    {
		printf("检测到命令可能执行失败,是否重试(y/N)");
		if (scanf("%c", &choose) == 1)
        {
            safe_flush(stdin);
            if (choose == 'y' || choose == 'Y')
			{
				for (int i = 1; i <= 3; i++)
				{
					printf("正在重试...(第%d次/共3次)\n", i);
					if (system(command) == 0)
						return;
				}
       			printf("命令多次执行失败,您可以继续操作,但造成的后果作者不予承担\n");
        		printf("是否继续操作(y/N)");
        		if (scanf("%c", &choose) == 1)
        		{
            		safe_flush(stdin);
            		if (choose == 'y' || choose == 'Y')
                		return;
            		else
                		exit(0);
       			 }
        		else
            		exit(0);
			}
            else
                exit(0);
        }
        else
            exit(0);
    }
    else
        return;
}
void clearscreen(void)
{
    if (OS_FLAG == "Windows")
	    system("CLS");
    else
        system("clear");
}
void safe_flush(FILE *fp)
{
	int ch;
	while( (ch = fgetc(fp)) != EOF && ch != '\n' );     
}
void checkkr(void)
{
    char *filename;
    FILE *fp;
    if (OS_FLAG == "Windows")
        filename = "bin\\KR.cycz";
    else
        filename = "bin/KR.cycz";
	fp = fopen(filename, "r");
	if (fp != NULL)
	{
		fclose(fp);
        printf("当前ROM需要扩容,请确定已经完成扩容!!!并按回车键继续\n");
        printf("当前ROM需要扩容,请确定已经完成扩容!!!并按回车键继续\n");
        printf("当前ROM需要扩容,请确定已经完成扩容!!!并按回车键继续");
		getchar();
		return;
	}
	else
		return;
}
int checkfile(char *filename)
{
	FILE *fp;
	fp = fopen(filename, "r");
	if (fp != NULL)
	{
		fclose(fp);
		return 0;
	}
	else
	{
		printf("文件\"%s\"不存在,请检查程序所在目录\n", filename);
		printf("按回车键退出程序");
		getchar();
		exit(0);
	}
}