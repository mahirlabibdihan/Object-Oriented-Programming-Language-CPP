#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
string Pi = "3.141592654";

class BigDecimal {
private:
	int AddCarry, SubCarry;
	string Value;
	BigDecimal Trim()
	{
		if (Value == "INFINTY") return *this;
		string Int, Frac;
		int i, n = Value.length();

		for (i = 0; i < n; i++)
		{
			if (Value[i] == '.') break;	
			Int += Value[i];
		}
		for (; i < n; i++)
		{
			Frac += Value[i];
		}

		if (Int[0] == '-')
		{
			while (Int.length() > 0 && Int[0] == '0')
			{
				Int.erase(Int.begin() + 1);
			} 
		}
			 
		else
		{
			while (Int.length() > 0 && Int[0] == '0')
			{
				Int.erase(Int.begin());
			}
		}
			
		while (Frac.length() > 0 && Frac.back() == '0')
		{
			Frac.pop_back();
		}
		if (Frac.length() > 0 && Frac.back() == '.')
		{
			Frac.pop_back();
		}

		string Number = Int + Frac;
		if (Number.length() > 0)  return (Value = Number);
		else return (Value = "0");
	}
	int Compare(BigDecimal b)
	{
		this->Trim();
		b.Trim();
		int i, n = this->Value.length(), m = b.Value.length();
		string Num1Int, Num1Frac, Num2Int, Num2Frac;

		for (i = 0; i < n; i++)
		{
			if (this->Value[i] == '.') break;
			Num1Int += this->Value[i];
		}
		for (i++; i < n; i++)
		{
			Num1Frac += this->Value[i];
		}

		for (i = 0; i < m; i++)
		{
			if (b.Value[i] == '.') break;
			Num2Int += b.Value[i];
		}
		for (i++; i < m; i++)
		{
			Num2Frac += b.Value[i];
		}

		if (Num1Int[0] == '-')
			while (Num1Int.length() > 0 && Num1Int[0] == '0')
			{
				Num1Int.erase(Num1Int.begin() + 1);
			}

		else
			while (Num1Int.length() > 0 && Num1Int[0] == '0')
			{
				Num1Int.erase(Num1Int.begin());
			}

		if (Num2Int[0] == '-')
			while (Num2Int.length() > 0 && Num2Int[0] == '0')
			{
				Num2Int.erase(Num2Int.begin() + 1);
			}

		else
			while (Num2Int.length() > 0 && Num2Int[0] == '0')
			{
				Num2Int.erase(Num2Int.begin());
			}

		while (Num1Frac.length() > 0 && Num1Frac.back() == '0')
		{
			Num1Frac.pop_back();
		}
		while (Num2Frac.length() > 0 && Num2Frac.back() == '0')
		{
			Num2Frac.pop_back();
		}

		if (Num1Int.length() == 0) Num1Int = "0";
		if (Num2Int.length() == 0) Num2Int = "0";
		if (Num1Frac.length() == 0) Num1Frac = "0";
		if (Num2Frac.length() == 0) Num2Frac = "0";

		if (Num1Int[0] == '-' && Num2Int[0] != '-') return -1;
		else if (Num1Int[0] != '-' && Num2Int[0] == '-') return 1;

		if (Num1Int.length() > Num2Int.length()) return 1;
		else if (Num1Int.length() == Num2Int.length())
		{
			if (Num1Int > Num2Int) return 1;
			else if (Num1Int == Num2Int)
			{
				if (Num1Frac > Num2Frac) return 1;
				else if (Num1Frac < Num2Frac) return -1;
				else return 0;
			}
			else return -1;
		}
		else return -1;
	}

	BigDecimal pop_front()
	{
		BigDecimal temp;
		temp.Value = this->Value.substr(1, Value.length() - 1);
		return temp;
	}
	string Add_Int(string a, string b)
	{
		string Addition;
		int i, n = a.length(), m = b.length();

		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		if (m > n) { swap(a, b); swap(n, m);}

		int p = max(m, n);

		for (i = 0; i < p; i++)
		{
			int temp, temp1, temp2;

			if (i > n - 1)
			{
				temp1 = 0;
			}
			else
			{
				temp1 = a[i] - 48;
			}

			if (i > m - 1)
			{
				temp2 = 0;
			}
			else
			{
				temp2 = b[i] - 48;
			}

			temp = temp1 + temp2 + AddCarry;
			AddCarry = temp / 10;
			Addition += (temp % 10) + 48;
		}

		if (AddCarry) Addition += AddCarry + '0';

		reverse(Addition.begin(), Addition.end());

		return Addition;
	}

	string Add_Frac(string a, string b)
	{
		string Addition;
		int i, n = a.length(), m = b.length();

		if (m > n) { swap(a, b); swap(n, m); }

		int p = max(m, n);

		for (i = p - 1; i > -1; i--)
		{
			int temp, temp1, temp2;

			if (i > n - 1)
			{
				temp1 = 0;
			}
			else
			{
				temp1 = a[i] - 48;
			}

			if (i > m - 1)
			{
				temp2 = 0;
			}
			else
			{
				temp2 = b[i] - 48;
			}

			temp = temp1 + temp2 + AddCarry;

			AddCarry = temp / 10;

			Addition += (temp % 10) + 48;
		}

		reverse(Addition.begin(), Addition.end());
		return (Addition.length() > 0 ? "." : "") + Addition;
	}




	string Sub_Int(string a, string b)
	{
		string Substitution;
		int i, n = a.length(), m = b.length();

		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());


		int p = max(m, n);

		for (i = 0; i < p; i++)
		{
			int temp, temp1, temp2;

			if (i > n - 1)
			{
				temp1 = 0;
			}
			else
			{
				temp1 = a[i] - 48;
			}

			if (i > m - 1)
			{
				temp2 = 0;
			}
			else
			{
				temp2 = b[i] - 48;
			}

			temp = temp1 - temp2 + 10 * (SubCarry + temp2 > temp1) - SubCarry;
			SubCarry = (SubCarry + temp2 > temp1);

			Substitution += temp + 48;
		}

		reverse(Substitution.begin(), Substitution.end());
		return Substitution;
	}

	string Sub_Frac(string a, string b)
	{
		string Substitution;
		int i, n = a.length(), m = b.length();

		int p = max(m, n);

		for (i = p - 1; i > -1; i--)
		{
			int temp, temp1, temp2;
			if (i > n - 1)
			{
				temp1 = 0;
			}
			else
			{
				temp1 = a[i] - 48;
			}

			if (i > m - 1)
			{
				temp2 = 0;
			}
			else
			{
				temp2 = b[i] - 48;
			}

			temp = temp1 - temp2 + 10 * (SubCarry + temp2 > temp1) - SubCarry;
			SubCarry = (SubCarry + temp2 > temp1);

			Substitution += temp + 48;
		}

		reverse(Substitution.begin(), Substitution.end());

		return (Substitution.length() > 0 ? "." : "") + Substitution;
	}


public:
	BigDecimal Add(BigDecimal Num)
	{
		AddCarry = 0;
		this->Trim();
		Num.Trim();
		bool Negative = false;
		if (this->Value[0] == '-' && Num.Value[0] == '-')
		{
			Negative = true;
			this->Value.erase(this->Value.begin());
			Num.Value.erase(Num.Value.begin());
		}
		else if (this->Value[0] == '-') return Num.Sub( this->pop_front());
		else if (Num.Value[0] == '-') return this->Sub( Num.pop_front());
		string Num1Int, Num1Frac, Num2Int, Num2Frac;

		int i, n = this->Value.length(), m = Num.Value.length();

		for (i = 0; i < n & this->Value[i] != '.'; i++)
		{
			Num1Int += this->Value[i];
		}

		for (i++; i < n; i++)
		{
			Num1Frac += this->Value[i];
		}

		for (i = 0; i < m & Num.Value[i] != '.'; i++)
		{
			Num2Int += Num.Value[i];
		}

		for (i++; i < m; i++)
		{
			Num2Frac += Num.Value[i];
		}

		string SumFrac = Add_Frac((Num1Frac > "" ? Num1Frac : "0"), (Num2Frac > "" ? Num2Frac : "0"));
		string SumInt = Add_Int((Num1Int > "" ? Num1Int : "0"), (Num2Int > "" ? Num2Int : "0"));

		while (SumInt[0] == '0') SumInt = SumInt.substr(1, SumInt.length());
		while (SumFrac.back() == '0') SumFrac.pop_back();
		if (SumFrac.back() == '.') SumFrac.pop_back();

		return (Negative ? "-" : "") + (SumInt > "" ? SumInt : "0") + (SumFrac > "" ? SumFrac : "");
	}

	BigDecimal Sub(BigDecimal Num)
	{
		SubCarry = 0;
		this->Trim();
		Num.Trim();
		if (this->Value[0] == '-' && Num.Value[0] == '-')
		{
			swap(this->Value, Num.Value);

		}
		else if (this->Value[0] == '-')
		{
			return this->Add("-" + Num.Value);
		}
		else if (Num.Value[0] == '-') return this->Add(Num.pop_front());
		string Num1Int, Num1Frac, Num2Int, Num2Frac;
		int i, n = this->Value.length(), m = Num.Value.length();
		bool Negative = false;

		for (i = 0; i < n & this->Value[i] != '.'; i++)
		{
			Num1Int += this->Value[i];
		}

		for (i++; i < n; i++)
		{
			Num1Frac += this->Value[i];
		}

		for (i = 0; i < m & Num.Value[i] != '.'; i++)
		{
			Num2Int += Num.Value[i];
		}

		for (i++; i < m; i++)
		{
			Num2Frac += Num.Value[i];
		}

		if (Num1Int.length() == 0) Num1Int = "0";
		if (Num2Int.length() == 0) Num2Int = "0";

		string SubFrac, SubInt;

		if (*this < Num)
		{
			SubFrac = Sub_Frac(Num2Frac, Num1Frac);
			SubInt = Sub_Int(Num2Int, Num1Int);
			Negative = true;
		}
		else
		{
			SubFrac = Sub_Frac(Num1Frac, Num2Frac);
			SubInt = Sub_Int(Num1Int, Num2Int);
		}

		if (SubInt.length())
			while (SubInt[0] == '0')
			{
				SubInt = SubInt.substr(1, SubInt.length());
			}

		if (SubFrac.length())
		{
			while (SubFrac.back() == '0')
			{
				SubFrac.pop_back();
			}
			if (SubFrac.back() == '.')
			{
				SubFrac.pop_back();
			}
		}

		string Substitution = (Negative ? "-" : "") + SubInt + SubFrac;
		if (Substitution.length()) return Substitution;
		return (BigDecimal)"0";
	}

	string To_String()
	{
		return this->Value;
	}

	string getValue()
	{
		return this->Value;
	}

	BigDecimal()
	{
		Value = "";
	}
	BigDecimal(string n)
	{
		Value = n;
	}
	BigDecimal operator= (string X)
	{
		Value = X;
		return *this;
	}
	BigDecimal operator= (const char* X)
	{
		Value = X;
		return *this;
	}
	char operator[] (int index)
	{
		return Value[index];
	}
	BigDecimal operator+= (char C)
	{
		Value += C;
		return *this;
	}
	BigDecimal operator+= (string S)
	{
		Value += S;
		return *this;
	}
	BigDecimal operator+= (const char* S)
	{
		Value += S;
		return *this;
	}

	BigDecimal operator+ (BigDecimal B)
	{
		return this->Add(B);
	}

	BigDecimal operator- (BigDecimal B)
	{
		return this->Sub(B);
	}

	bool operator== (BigDecimal B)
	{
		return this->Compare(B) == 0;
	}

	bool operator> (BigDecimal B)
	{
		return this->Compare(B) == 1;
	}

	bool operator< (BigDecimal B)
	{
		return this->Compare(B) == 1;
	}

	bool operator>= (BigDecimal B)
	{
		return this->Compare(B) > -1;
	}

	bool operator<= (BigDecimal B)
	{
		return this->Compare(B) < 1;
	}

	BigDecimal operator+ (string B)
	{
		return Value + B;
	}

	BigDecimal operator+ (char B)
	{
		return Value + B;
	}

	friend ostream& operator << (ostream& os, const BigDecimal& Out);
	friend istream& operator >> (istream& is, BigDecimal& In);
};
istream& operator >> (istream& is, BigDecimal& In)
{
	is >> (In.Value);
	return is;
}
ostream& operator << (ostream& os, const BigDecimal& Out)
{
	os << (Out.Value);
	return os;
}

class Equation {
	string Equ;
	void operator= (BigDecimal X)
	{
		Equ = X.getValue();
	}
	bool hasPrecedence(char op1, char op2)
	{
		if (op2 == '(' || op2 == ')')
			return false;
		if ((op1 == '^' || op1 == '*' || op1 == '/' || op1 == '%' || op1 == '!' || op1 == 'p' || op1 == 'c' || op1 == 'g' || op1 == 'l' || op1 == '&' || op1 == '|') && (op2 == '+' || op2 == '-'))
			return false;
		if ((op1 == '^' || op1 == '!' || op1 == 'p' || op1 == 'c' || op1 == 'g' || op1 == 'l' || op1 == '&' || op1 == '|') && (op2 == '*' || op2 == '/' || op2 == '%'))
			return false;
		if ((op1 == '!' || op1 == '^' ) && ( op2 == 'p' || op2 == 'c' || op2 == 'g' || op2 == 'l' || op2 == '&' || op2 == '|'))
			return false;
		if (op1 == '!' && op2 == '^')
			return false;
		else
			return true;
	}

	BigDecimal applyOp(char op, BigDecimal b, BigDecimal a)
	{
		// cout<<op<<endl;
		switch (op) {
		case '+':
			return a + b;
			break;
		case '-':
			return a - b;
			break;
			// case '*':
			// 	return Mul(a, b);
			// 	break;
			// case '^':
			// 	return Power(a, b);
			// 	break;
			// case '%': return Mod(a, b);
			// 	break;
			// case '/': return Div(a, b);
			// 	break;
			// case '!': return Factorial(b);
			// 	break;
			// case 'p': return NPR(a, b);
			// 	break;
			// case 'c': return NCR(a, b);
			// 	break;
			// case 'g': return GCD(a, b);
			// 	break;
			// case 'l': return LCM(a, b);
			// 	break;
			// case '&': return And(a, b);
			// 	break;
			// case '|': return Or(a, b);
			// 	break;
		}
		return a;
	}


	BigDecimal Bodmash()
	{
		if (Equ.length() == 0) return (string)"0";

		stack<BigDecimal> values;
		stack<char> ops;

		for (int i = 0; i < Equ.length(); i++)
		{
			if (Equ[i] == ' ') continue;
			if ((Equ[i] >= '0' && Equ[i] <= '9') || Equ[i] == '.') {
				BigDecimal num;
				while (i < Equ.length() && (Equ[i] >= '0' && Equ[i] <= '9' || Equ[i] == '.'))
				{
					num = num + Equ[i++];
				}
				i--;
				values.push(num);
			}
			else if (Equ[i] == '(') ops.push(Equ[i]);

			else if (Equ[i] == ')') {
				while (ops.top() != '(') {
					BigDecimal value1, value2;
					if (!values.empty()) {
						value1 = values.top();
						values.pop();
					}
					else value1 = "0";
					if (!values.empty()) {
						value2 = values.top();
						values.pop();
					} else value2 = "0";
					values.push(applyOp(ops.top(), value1, value2));
					ops.pop();
				}
				ops.pop();
			}

			else if (Equ[i] == '+' || Equ[i] == '-' || Equ[i] == '*' || Equ[i] == '/' || Equ[i] == '%' || Equ[i] == '^' || Equ[i] == 'p' || Equ[i] == 'c' || Equ[i] == 'g' || Equ[i] == 'l' || Equ[i] == '&' || Equ[i] == '|'  )
			{
				while (!ops.empty() && hasPrecedence(Equ[i], ops.top())) {
					BigDecimal value1, value2;
					if (!values.empty()) {
						value1 = values.top();
						values.pop();
					}
					else value1 = "0";
					if (!values.empty()) {
						value2 = values.top();
						values.pop();
					} else value2 = "0";
					values.push(applyOp(ops.top(), value1, value2));
					ops.pop();
				}
				ops.push(Equ[i]);
			}

			else if (Equ[i] == '!')
			{
				while (!ops.empty() && hasPrecedence(Equ[i], ops.top()))
				{
					BigDecimal value = values.top();
					values.pop();
					values.push(applyOp(ops.top(), value, value));
					ops.pop();
				}
				ops.push(Equ[i]);
			}
		}

		while (!ops.empty()) {
			BigDecimal value1, value2;
			if (!values.empty()) {
				value1 = values.top();
				values.pop();
			}
			else value1 = "0";
			if (!values.empty()) {
				value2 = values.top();
				values.pop();
			} else
				value2 = "0";

			values.push(applyOp(ops.top(), value1, value2));
			ops.pop();

		}

		BigDecimal temp = values.top();
		values.pop();
		return temp;

	}
public:
	friend istream& operator >> (istream &is, Equation& In);
	friend ostream& operator << (ostream& os, const Equation& Out);
	BigDecimal Solve()
	{
		return Bodmash();
	}
};

istream& operator>> (istream &is, Equation &In)
{
	getline(is, In.Equ);
	return is;
}
ostream& operator<< (ostream& os, const Equation& Out)
{
	os << Out.Equ;
	return os;
}

int main()
{
	Equation In;
	cin >> In, cout << In.Solve() << endl;
	BigDecimal x("123");
	x += "456";
	cout << x;
}