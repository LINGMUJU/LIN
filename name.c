#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//定义最大容量与最大长度
#define Max_Length 50
//#define Max_Numbers 100

//储存单个用户的结构体
struct User{
    char user[Max_Length];
    char user_number[Max_Length];
};

struct Userdatabase{
    struct User *users;
    struct User *user_numbers;
    int count;
};

//初始化数据库
void userinitialize(struct Userdatabase *db){
    db->users = 0;
    db->count = 0;
}
//注册用户
int adduser(struct Userdatabase* db, const char* user, const char* user_number){
    struct User *nextusers = realloc(db->users,(db->count+1)*Max_Length);
    if(nextusers==NULL){
        return 0;
    }
    db->users=nextusers;
    strncpy(db->users[db->count].user,user,Max_Length-1);
    strncpy(db->users[db->count].user_number,user_number,Max_Length-1);
    db->count++;
    return 1;
}
//查找用户
int finduser(const struct Userdatabase *db,const char* user){
    for(int i=0; i<db->count; i++){
        if(strcmp(db->users[db->count].user,user)==0){
            return 1;
        }
    }
    return 0;
}
//储存单个姓名的结构体
struct Name{
    char name[Max_Length];
};

//数据库的结构体
struct Database{
    struct Name *names;
    int count;
};

//初始化数据库
void initialize(struct Database* db){
    db->names = NULL;
    db->count = 0;
}

//添加姓名
int addname(struct Database* db, const char* name){
    struct Name *nextnames = realloc(db->names,(db->count+1)*Max_Length);
    if(nextnames==NULL){
        return 0;
    }
    db->names=nextnames;//更新指针
    strncpy(db->names[db->count].name, name, Max_Length-1);
    db->names[db->count].name[Max_Length-1]='\0';
    db->count++;
    return 1;
    
}

//列出所有数据
void listname(const struct Database* db){
    for(int i=0; i < db->count; i++){
        printf("name,%s\n",db->names[i].name);
    }
}

void FREE(struct Database* db){
    free(db->names);
}

void FREE(struct Userdatabase* db){
    free(db->users);
}

int main(){
    struct Database NAME;

    initialize(&NAME);
    //注册
    printf("regiser in, and 'next' if u has regiser\n");
    char input[Max_Length];
    fgets(input,sizeof(input),stdin);
    if(strcmp(input,"next\n")==0){
        
    }
    input[strcspn(input,"\n")]='\0';
    printf("please input name, and 'quit' is exit\n");
   
    while(1){
        fgets(input,sizeof(input),stdin);
        if(strcmp(input,"quit\n")==0)
            break;
        input[strcspn(input,"\n")]='\0';
        addname(&NAME,input);
    }

    listname(&NAME);
    FREE(&NAME);

    system("pause");
    return 0;

}

