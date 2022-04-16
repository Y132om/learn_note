#include "../include/shared_ptr.h"
using namespace std;

int main()
{
  shared_ptr<string> p1=make_shared<string>("tom");
  shared_ptr<string> p2=make_shared<string>("jerry");

  (*p1)[0]='T';
  p2->replace(0,1,"J");

  cout<< *p1 <<" " << *p2 << endl;


  vector<shared_ptr<string>> vPtrShared;

  vPtrShared.push_back(p1);
  vPtrShared.push_back(p2);
  vPtrShared.push_back(p1);

  vector<shared_ptr<string>>::iterator iter;
  for (vector<shared_ptr<string>>::iterator iter = vPtrShared.begin();iter != vPtrShared.end(); iter++)
  {
	  cout << "address::" << *iter << endl; //�洢����ָ�룬��ӡ�����ǵ�ַ
	  cout << "value::" << *(*iter) << endl;//������
  }

  *p1 = "Sam";  //ͬһ����ַ�����ݲ�һ��

  for (vector<shared_ptr<string>>::iterator iter=vPtrShared.begin();iter!=vPtrShared.end();iter++)
  {
	  cout << "address::"<< *iter<<endl;
	  cout << "value::"<< *(*iter)<<endl;
  }
}

 