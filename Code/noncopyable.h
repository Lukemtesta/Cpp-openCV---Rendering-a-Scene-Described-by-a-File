#ifndef NONCOPYABLE_H_
#define NONCOPYABLE_H_

/*
Simple ancestor class for preventing accidental copying. 
Objects that inherit from it will not allow default copy construction or assignment
*/
class noncopyable {
protected:
	noncopyable(){}
	virtual ~noncopyable(){}

private:
	noncopyable( const noncopyable & );
	noncopyable & operator=( const noncopyable & );
};


#endif /* NONCOPYABLE_H_ */
