#ifndef PRIORITIES_HPP
#define PRIORITIES_HPP

#include "schueler.h"
#include <list>


/// <summary>
/// This class handles the priority que. Its items are objects of the class "schueler"
/// </summary>
class priorities 
{
private:
	std::list<schueler> list_schuelerList;                       //priority que
	void push(int int_id, std::string str_name, double d_cgpa);  //adds a new item to the que
	void pop();                                                  //removes  the item with the highest priority from the que
	int int_itemCounter;                                         //counter of the amount of items in the que, max is 1000
 
public:	
	priorities();
	~priorities();

	/// <summary>
	/// Function to process events in order to add or remove items from the que
	/// In the task definition this function was called "List<Schüler> getSchülers(List<String>events)"
	/// </summary>
	/// <param name="events"> The function can handle the two events "ENTER" and "SERVED". Invalid Events are ignored </param>
	/// <returns> Returns the priority que with all items. The item with the highest priority comes first </returns>
	std::list<schueler> processEvents(std::list<std::string> events);

};

#endif // PRIORITIES_HPP
