#include "StrVec.h"

std::allocator<string> StrVec::alloc;

void StrVec::push_back( const string& s )
{
	chk_n_alloc(); // ȷ���пռ�������Ԫ��
	// first_freeָ���Ԫ���й���s�ĸ���
	alloc.construct(first_free++,s)  ; 
	
	
	
}
pair<string* ,string* > StrVec::alloc_n_copy(const string* b, const string* e )
{
	auto data = alloc.allocate(e-b);
	return make_pair(data , uninitialized_copy(b,e,data)  );
	
	
}
void StrVec::free()
{
	// ���ܴ��ݸ�deallcoateһ����ָ��
	if( elements)
	{
		for(auto p = first_free ; p != elements ; )
			alloc.destroy(--p);
		alloc.deallocate(elements,cap-elements) ;
	}
	
	
}
StrVec& StrVec::operator=( const StrVec& rhs )
{
	auto data = alloc_n_copy(rhs.begin() , rhs.end() );
	free() ;
	elements = data.first ;
	first_free= cap=data.second;
	
	return *this ;
	
}
void StrVec::reallocate()
{
	// ���ǽ����䵱ǰ��С�������ڴ�ռ�;
	auto newcapacity  = size() ? 2*size() :1 ;
	//�������ڴ�
	auto newdata = alloc.allocate( newcapacity ) ;
	
	auto dest=newdata ;
	auto elem = elements ;
	for(size_t i=0; i != size() ; i++)
		alloc.construct(dest++,std::move( *elem++) );
	free();
	elements = newdata;
	first_free = dest ;
	cap = elements+ newcapacity ;
	
	
	
	
}
StrVec::~StrVec()
{
	free();
}