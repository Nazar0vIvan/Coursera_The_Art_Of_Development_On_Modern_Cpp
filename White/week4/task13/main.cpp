#include <iostream>
#include <string>

using namespace std;

string AskTimeServer() {
    char responce = 'f';
    string server_time = "00:00:01";
    if (responce == 'f')
        throw system_error(error_code());
    else if (responce == 't'){
        throw domain_error("");
    }
    else{
        return server_time;
    }
}

class TimeServer {
public:
    string GetCurrentTime(){
        try {
            last_fetched_time = AskTimeServer();
        }
        catch (system_error& ex) {
            return last_fetched_time;
        }
        catch (domain_error& ex){
            throw domain_error("another exception");
        }
        return last_fetched_time;
    }
private:
    string last_fetched_time = "00:00:00";
};

int main()
{
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}
