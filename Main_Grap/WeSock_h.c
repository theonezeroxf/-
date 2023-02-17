#include"WeSock_h.h"

void inttostr(const int i,char *p){
    int tem=i;
    for(int j=0;j<3;j++){
        *(p+j) = (tem%10)+48;
        tem/=10;
    }
}

int strtoint(char *p){
    int tem=0;
    for(int j=0;j<3;j++){
        int i = *(p+j) - 48 ;
        if(i < 0 || i >= 10) return -1;
        tem = tem*10 + *(p+j) - 48;
    }
    return tem;
}

struct WePro Package(const unsigned char Cmd,char *name,int day,int slptime,int wen,int shen,int guang){
    struct WePro por;
    por.cmd=Cmd;
    if(name) strcpy(por.Name,name);
    else por.Name[0]='\0';
    por.Day=day;
    por.Slptime=slptime;
    por.Wen=wen;
    por.Shen=shen;
    por.Guang=guang;
    return por;
}

unsigned char Parse(char *pro,char *name,int *day,int *slptime,int *wen,int *shen,int *guang){
    wepro p = (wepro) pro ;
    strcpy(name,p->Name);
    *day = p->Day;
    *slptime = p->Slptime;
    *wen = p->Wen;
    *shen = p->Shen;
    *guang = p->Guang;
    return p->cmd;
}