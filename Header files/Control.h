#ifndef CONTROL_H
#define CONTROL_H

#include "Telco.h"
#include "View.h"

class Control
{
  public:
  	Control();
  	~Control();
  	void launch();

  private:
  	View *view;
  	Telco *telco;
  
  	void initData(Telco *t);
  	void initSubscribers(Telco *t);
  	void initCalls(Telco *t);

};

#endif
