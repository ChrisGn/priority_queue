#include "schueler.h"
#include <list>



class priorities 
{
private:
	std::list<schueler> list_schuelerList;
	bool checkEvents(std::list<std::string> events);
	void push(int id, std::string name, double cgpa);
	void pop();
 
public:	
	priorities();
	~priorities();
	std::list<schueler> getSchuelerList();
	std::list<schueler> processEvents(std::list<std::string> events);

};
