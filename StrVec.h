#ifndef STRVEC_H
#define STRVEC_H

#include<iostream>
#include<string>
#include<memory>
using namespace std;
class StrVec{
public:
	// Ĭ�Ϲ��캯��
	StrVec():elements(nullptr),first_free(nullptr),cap(nullptr)
	{
		
	}
	//�������캯��
	StrVec(const StrVec& );
	//������ֵ�����
	StrVec& operator=(const StrVec&);
	~StrVec();
	void push_back(const string&);
	size_t size() const { return first_free - elements ; }
	size_t capacity() const {  return cap - elements  ;}
	string* begin() const { return elements ;}
	string* end() const { return first_free ;}
	
	
	
private:
static allocator<string> alloc;  // ����Ԫ��
 // ����ӵ�Ԫ�صĺ���ʹ��
 void chk_n_alloc()
 {
	 if( size() == capacity() )
	        reallocate();
		
		
 }
// ���ߺ��������������캯������ֵ�����������������ʹ��
pair<string* ,string*> alloc_n_copy(const string* ,const string* );

	
	

  
void free();
void reallocate();
string* elements; // ָ��������Ԫ�ص�ָ��
string* first_free; // ָ�������һ������Ԫ�ص�ָ��
string* cap; // ָ������β���ָ��

	
};






#endif