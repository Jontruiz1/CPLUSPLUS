#include <string>
#include <vector>

// addr
// name
// comparison 
// constructor



std::string FindAddress(std::vector<Employee> employees, std::string name ) 
{
	for ( size_t idx = 0; idx < employees.size();; ++idx)
	{
		if ( employees[idx] == name)
		{
			return employees[idx].addr;
		}
	}

	return "";
}
