#pragma once

class Computer
{
	static size_t _staticId;
	size_t _id;
	char* _model;
	char* _color;
	ushort _year;
	char* _CPU; // Intel Core i7-8550U
	ushort _RAM;
	ushort _space; // (Hard disc or SSD)

public:

	// All Constructors

	Computer();
	Computer(const char* _model, const char* _color, ushort _year, const char* _CPU, ushort _RAM, ushort _space);
	Computer(const char* _model, const char* _color, ushort _year , ushort _RAM, ushort _space);
	Computer(const char* _model, const char* _color , ushort _year, ushort _RAM);
	Computer(const char* _model, const char* _color);
	Computer(const char* _model);

	// Copy Constructor
	
	Computer(const Computer& other);

	// Copy Assigment Operator

	Computer& operator = (const Computer& other);

	// Get Methods
	
	inline static size_t get_static_id();
	inline size_t get_id() const;
	inline const char const* get_model() const;
	inline const char const* get_color() const;
	inline ushort get_year() const;
	inline const char const* get_CPU() const;
	inline ushort get_RAM() const;
	inline ushort get_space() const;

	// Set Methods

	void set_model(const char* _model);
	void set_color(const char* _color);
	void set_year(ushort _year);
	void set_CPU(const char* _CPU);
	void set_RAM(ushort _RAM);
	void set_space(ushort _space);

	//Print 

	void print() const;

	// Destructor

	~Computer();
};