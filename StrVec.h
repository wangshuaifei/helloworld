#ifndef STRVEC_H
#define STRVEC_H

#include<iostream>
#include<string>
#include<memory>
using namespace std;
class StrVec{
public:
	// 默认构造函数
	StrVec():elements(nullptr),first_free(nullptr),cap(nullptr)
	{
		
	}
	//拷贝构造函数
	StrVec(const StrVec& );
	//拷贝赋值运算符
	StrVec& operator=(const StrVec&);
	~StrVec();
	void push_back(const string&);
	size_t size() const { return first_free - elements ; }
	size_t capacity() const {  return cap - elements  ;}
	string* begin() const { return elements ;}
	string* end() const { return first_free ;}
	
	
	
private:
static allocator<string> alloc;  // 分配元素
 // 被添加的元素的函数使用
 void chk_n_alloc()
 {
	 if( size() == capacity() )
	        reallocate();
		
		
 }
// 工具函数，被拷贝构造函数、赋值运算符和析构函数所使用
pair<string* ,string*> alloc_n_copy(const string* ,const string* );

	
	

  
void free();
void reallocate();
string* elements; // 指向数组首元素的指针
string* first_free; // 指向数组第一个空闲元素的指针
string* cap; // 指向数组尾后的指针

	
};






#endif