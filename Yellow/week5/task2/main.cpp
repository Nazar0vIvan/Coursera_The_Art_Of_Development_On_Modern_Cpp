#include <iostream>
#include <string>

using namespace std;

void SendSms(const string& number, const string& message)
{
  cout << "Send '" << message << "' to number " << number << endl;
}

void SendEmail(const string& email, const string& message)
{
  cout << "Send '" << message << "' to e-mail "  << email << endl;
}

class INotifier
{
public:
  INotifier(){}
  virtual void Notify(const string& message) = 0;
};

class SmsNotifier : public INotifier
{
public:
  SmsNotifier(const string& number) : m_number(number){}
  void Notify(const string& message) override {
      SendSms(m_number,message);
  }
private:
  string m_number;
};

class EmailNotifier : public INotifier
{
public:
  EmailNotifier(const string& email) : m_email(email){}
  void Notify(const string& message) override {
      SendEmail(m_email,message);
  }
private:
  string m_email;
};

void Notify(INotifier& notifier, const string& message)
{
  notifier.Notify(message);
}

int main()
{
  SmsNotifier sms{"+7-495-777-77-77"};
  EmailNotifier email{"na-derevnyu@dedushke.ru"};

  Notify(sms, "I have White belt in C++");
  Notify(email, "And want a Yellow one");

  return 0;
}
