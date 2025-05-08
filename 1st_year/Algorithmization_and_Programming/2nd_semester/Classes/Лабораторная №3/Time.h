class Time
{
	int min;
	int sec;
public:
	Time();
	Time(int, int);
	Time(const Time&);
	~Time();

	int getMin();
	int getSec();

	void setMin(int);
	void setSec(int);
	
	Time& operator= (const Time&);
	Time& operator-- ();
	Time operator-- (int);
	Time& operator++ ();
	Time operator++ (int);


	friend istream& operator>> (istream&, Time& );
	friend ostream& operator<< (ostream&, const Time&);
};
