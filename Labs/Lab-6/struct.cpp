#include <iostream>
#include <string>
struct Address{
private:
	std::string street;
	std::string city;
	std::string state;
	int zip;
	std::string apt;
public:
	std::string getStreet(){
		return street;
	}
	void setStreet(std::string &value){
		street = value;
	}
	std::string getCity(){
		return city;
	}
	void setCity(std::string &value){
		city = value;
	}
	std::string getState(){
		return state;
	}
	void setState(std::string &value){
		state = value;
	}
	int getZip(){
		return zip;
	}
	void setZip(int &value){
		zip = value;
	}
	std::string getApt(){
		return apt;
	}
	void setApt(std::string &value){
		apt = value;
	}	
};	
struct BankAccount{
private:
	int account_number;
	std::string account_type;
	double balance;
	std::string beneficiaries;
public:
	int getAccountNumber(){
		return account_number;
	}
	void setAcountNumber(int value){
		account_number = value;
	}
	std::string getAccountType(){
		return account_type;
	}
	void setAccountType(std::string value){
		account_type = value;
	}
	double getBalance(){
		return balance;
	}
	void setDouble(double value){
		balance = value;
	}
	std::string getBeneficiaries(){
		return beneficiaries;
	}
	void setBeneficiaries(std::string value){
		beneficiaries = value;
	}
};
struct Customer{
private:
	std::string first_name;
	std::string last_name;
	Address address;
	BankAccount account[5];
public:
	std::string getFirstName(){
		return first_name;
	}
	void setFirstName(std::string value){
		first_name = value;
	}
	std::string getLastName(){
		return last_name;
	}
	void getLastName(std::string value){
		last_name = value;
	}
	Address getAddress(){
		return address;
	}
	void setAddress(Address name, Address val){
		adress.name = val;
	}
	BankAccount getAccount();
	void setAccount(BankAccount name, BankAccount val);
};
Customer largestAccount(Customer &customer);
int main(){
	Address address;
	address.setStreet("Test");
	address.setCity("Hollis");
	std::cout << address.getStreet() << std::endl;
	std::cout << address.getCity() <<std::endl;	
}
Customer::Customer largestAccount(Customer::Customer customer){
	
}