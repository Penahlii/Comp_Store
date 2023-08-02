#pragma once

class CompStore
{
	char* _name;
	Computer** _computers;
	size_t _count;

public:

	// All Constructors

	CompStore();
	CompStore(const char* _name, Computer** _computers, size_t _count);
	CompStore(Computer** _computers, size_t count);
	CompStore(const char* _name);

	// Copy Constructor

	CompStore(const CompStore& other);

	// Copy Assigment Operator

	CompStore& operator = (const CompStore& other);

	// Get Methods

	inline const char const* get_name() const;
	inline size_t get_count() const;

	// Set Methods

	void set_computers(Computer**& _computers, size_t count);
	void set_name(const char* _name);

	// + methods

	//void print_computers_years_between(size_t min_year, size_t max_year);
	//void print_samse_computers_model(const char* model); // same models
	//void print_computers_ram_greater_than(int min_ram);
	//Computer** getComputersByColor(const char* color);
	//void print_same_computers_year(size_t year); // same year
	//Computer* get_computer_by_id(size_t id);
	void clear() const;

	// Print

	void print() const;

	// Destructor

	~CompStore();
};