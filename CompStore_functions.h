#pragma once

// All Constructors

CompStore::CompStore()
{
	this->_name = nullptr;
	this->_computers = nullptr;
	this->_count = 0;
}
CompStore::CompStore(const char* _name, Computer** _computers, size_t count) : CompStore(_computers , count)
{
	set_name(_name);
}

CompStore::CompStore(Computer** _computers, size_t count) : CompStore()
{
	set_computers(_computers , count);
}

CompStore::CompStore(const char* _name) : CompStore()
{
	set_name(_name);
}

// Set Methods

void CompStore::set_computers(Computer**& _computers , size_t count)
{
	if (_computers != nullptr)
	{
		this->_count = count;
		this->clear();
		this->_computers = new Computer * [count];
		for (size_t i = 0; i < count; i++)
			this->_computers[i] = new Computer(_computers[i]->get_model(), _computers[i]->get_color(), _computers[i]->get_year(), _computers[i]->get_CPU(), _computers[i]->get_RAM(), _computers[i]->get_space());
		return;
	}	
	assert(!"Can not send NULL Data !!!");
}

void CompStore::set_name(const char* _name)
{
	int len = strlen(_name);
	if (len >= 1)
	{
		if (len >= 3)
		{
			if (this->_name != nullptr)
				delete[] this->_name;
			this->_name = new char[len + 1];
			strcpy_s(this->_name, len + 1, _name);
			return;
		}
		assert(!"Lenght of name is not correct !!!");
	}
	assert(!"Can not send NULL Data !!!");
}

// Get Methods

inline const char const* CompStore::get_name() const { return (this->_name != nullptr ? this->_name : error); }
inline size_t CompStore::get_count() const { return this->_count; }

// Copy Constructor

CompStore::CompStore(const CompStore& other)
{
	set_name(other._name);
	this->_count = other._count;
	this->_computers = new Computer * [other._count];
	for (size_t i = 0; i < other._count; i++)
		this->_computers[i] = new Computer(*(other._computers[i]));
}

// Copy Assigment Operator

CompStore& CompStore::operator = (const CompStore& other)
{
	this->set_name(other._name);
	this->_count = other._count;
	this->clear();
	this->_computers = new Computer * [other._count];
	for (size_t i = 0; i < this->_count; i++)
	{
		this->_computers[i] = new Computer(*(this->_computers[i]) = *(other._computers[i]));
	}

	return *this;
}

// Print

void CompStore::print() const
{
	cout << "Name: " << (this->_name != nullptr ? this->_name : "NULL") << endl;
	if (this->_computers != nullptr)
	{
		cout << "\t\tComputers: " << endl;
		for (size_t i = 0; i < this->_count; i++)
		{
			this->_computers[i]->print();
		}
		cout << endl;
		cout << "Computers' count: " << this->_count << endl;
	}
	else
		cout << "There is not any computer in Computer Shop yet !!";
}

// clear

void CompStore::clear() const
{
	if (this->_computers != nullptr)
	{
		for (size_t i = 0; i < this->_count; i++)
			delete this->_computers[i];
		delete[] this->_computers;
 	}
}

// Destructor

CompStore::~CompStore()
{
	if (this->_name != nullptr)
		delete[] this->_name;
	this->clear();
}