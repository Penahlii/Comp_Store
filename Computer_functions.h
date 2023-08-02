#pragma once

// static ID

size_t Computer::_staticId = 1;

// All comstructors

Computer::Computer()
{
	this->_id = _staticId++;
	this->_model = nullptr;
	this->_color = nullptr;
	this->_year = 0;
	this->_CPU = nullptr;
	this->_RAM = 0;
	this->_space = 0;
}

Computer::Computer(const char* _model, const char* _color, ushort _year, const char* _CPU, ushort _RAM, ushort _space) : Computer(_model, _color, _year, _RAM, _space)
{
	set_CPU(_CPU);
}

Computer::Computer(const char* _model, const char* _color, ushort _year, ushort _RAM, ushort _space) : Computer(_model , _color , _year , _RAM)
{
	set_space(_space);
}

Computer::Computer(const char* _model, const char* _color, ushort _year, ushort _RAM) : Computer(_model , _color)
{
	set_year(_year);
	set_RAM(_RAM);
}

Computer::Computer(const char* _model, const char* _color) : Computer(_model)
{
	set_color(_color);
}

Computer::Computer(const char* _model) : Computer()
{
	set_model(_model);
}

// Set methods

void Computer::set_model(const char* _model)
{
	int len = strlen(_model);
	if (len>=1)
	{
		if (len >= 3)
		{
			if (this->_model != nullptr)
				delete[] this->_model;
			this->_model = new char[len + 1];
			strcpy_s(this->_model, len+1, _model);
			return;
		}
		assert(!"Lenght of model should be 3 or more !!!");
	}
	assert(!"Can not send NULL Data !!!");
}

void Computer::set_color(const char* _color)
{
	int len = strlen(_color);
	if(len >= 1)
	{
		if (this->_color != nullptr)
			delete[] this->_color;
		this->_color = new char[len + 1];
		strcpy_s(this->_color, len + 1, _color);
		return;
	}
	assert(!"Can not send NULL Data !!!");
}

void Computer::set_year(ushort _year)
{
	if (_year >= 2000 && _year <= 2024)
		this->_year = _year;
	else
		assert(!"Wrong year !!!");
}

void Computer::set_CPU(const char* _CPU)
{
	int len = strlen(_CPU);
	if (len >= 1)
	{
		if (len >= 3)
		{
			if (this->_CPU != nullptr)
				delete[] this->_CPU;
			this->_CPU = new char[len + 1];
			strcpy_s(this->_CPU, len + 1, _CPU);
			return;
		}
		assert(!"Lenght of CPU must be 3 at least !!!");
	}
	assert(!"Can not send NULL Data !!!");
}

void Computer::set_RAM(ushort _RAM)
{
	if (_RAM >= 4 && _RAM <= 32)
		this->_RAM = _RAM;
	else
		assert(!"RAM is not correct !!!");
}

void Computer::set_space(ushort _space)
{
	if (_space >= 128 && _space <= 2048)
		this->_space = _space;
	else
		assert(!"Wrong space!!!");
}

// Get methods

inline size_t Computer::get_static_id() { return _staticId; }
inline size_t Computer::get_id() const { return this->_id; }
inline const char const* Computer::get_model() const { return (this->_model != nullptr ? this->_model : error); }
inline const char const* Computer::get_color() const { return (this->_color != nullptr ? this->_color : error); }
inline ushort Computer::get_year() const { return this->_year; }
inline const char const* Computer::get_CPU() const { return (this->_CPU != nullptr ? this->_CPU : error); }
inline ushort Computer::get_RAM() const { return this->_RAM; }
inline ushort Computer::get_space() const { return this->_space; }

// Copy constructor

Computer::Computer(const Computer& other)
{
	_id = _staticId++;
	set_model(other._model);
	set_color(other._color);
	set_year(other._year);
	set_CPU(other._CPU);
	set_RAM(other._RAM);
	set_space(other._space);
}

// Copy Assigment operator

Computer& Computer::operator = (const Computer& other)
{
	this->set_model(other._model);
	this->set_color(other._color);
	this->set_year(other._year);
	this->set_CPU(other._CPU);
	this->set_RAM(other._RAM);
	this->set_space(other._space);

	return *this;
}

//print 

void Computer::print() const
{
	cout << "ID: " << this->_id << endl;
	cout << "Model: " << (this->_model != nullptr ? this->_model : "NULL") << endl;
	cout << "Color: " << (this->_color != nullptr ? this->_color : "NULL") << endl;
	cout << "Year: " << this->_year << endl;
	cout << "CPU: " << (this->_CPU != nullptr ? this->_CPU : "NULL") << endl;
	cout << "RAM: " << this->_RAM << endl;
	cout << "Space: " << this->_space << endl << endl;
}

// destructor

Computer::~Computer()
{
	if (this->_model != nullptr)
		delete[] this->_model;
	if (this-> _CPU != nullptr)
		delete[] this->_CPU;
	if (this->_color != nullptr)
		delete[] this->_color;
}