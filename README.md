# learn_note
学习笔记、面试复习、涵盖C++，Python,Cuda,深度学习模型压缩等，详细内容不间断更新。

## C++ 核心学习 


## 智能指针
### 普通指针的问题
- 资源泄露
```C++
int main()
{
    int *p=new int;
    *p=1;
    p=new int;//错误，之前的内存已经泄露
    delete p;
    return 0;
}
```
- 迷途指针
```C++
int main()
{
    int *p1=new int;
    int *p2=p1;
    delete p1;
    *p2=1;//错误，p2指向的内存已经被释放
    return 0;
}
```

- 野指针
```C++
int main()
{
    int *p;
    *p=1; //错误，未初始化，野指针
    return 0;
}
```

**解决办法：智能指针**
1. shared_ptr:C++11共享所有权
2. unique_ptr:C++11独占权
3. auto_ptr:C++中已废弃

### 共享指针shared_ptr特性
1. 具有共享所有权予以
2. 每当shared_ptr的最后一个所有者被销毁时，关联对象都将被删除(或关联资源被清楚);
#### 创建方式
方式一:
```C++
shared_ptr<string> p{new string("tom")};
```
方式二: 
```C++
shared_ptr<string> p;
p.reset(new string ("tom"));
```
方式三：
```C++
shared_ptr<string> p=make_shared<string>("tom");
```
推荐方式三：更快 一次复制，更安全。

#### 使用
```C++
shared_ptr<string> p1=make_shared<string>("tom");
shared_ptr<string> p2=make_shared<string>("jerry");

(*p1)[0]='T';
p2->replace(0,1,"i");

vector<shared_ptr<string>> vt;
vt.push_back(p1);
vt.push_back(p2);
vt.push_back(p1);

//vt 内容为 tom jerry tom

*p1="tomy";
//vt 内容为 tomy jerry tomy
```
- `*p1`,解引用
- `p2->repalce` 解引用，并调用成员函数
- 向容器插入p1,只是增加一次引用

引用计数法

## cuda

## Python

## CPython

## numba

## 深度学习模型压缩