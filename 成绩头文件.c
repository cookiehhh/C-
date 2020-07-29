void ListMenu( ); //显示主菜单
void outputmenu( ); //输出二级菜单
void inputmenu( ); //输入二级菜单
int  coursemenu( );//课程菜单，返回课程号1，2，3

void inputbyCrsId(int CrsId); //按课程号输入某科成绩
void outputbyno( );//按学号输出成绩
void process(); //统计各科、各个同学的总分
void sortfun() ;//可以按照单科或者总分对名次排序
void randdata() ; //产生随机数作为测试数据
void outputbyrank(int n) ; //按名次输出成绩前几名
void failacourse(int courseID) ; //输出某科不及格名单
void outputfail(); //输出不及格名单
void output(); //输出功能的控制函数
void input();//输入功能的控制函数

void allfail(); //输出所有科目不及格名单