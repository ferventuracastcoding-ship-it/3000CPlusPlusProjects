#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Debugger {

private:

    string programName;
    vector<int> breakpoints;

    map<string,int> variables;


public:

    Debugger(string name)
    {
        programName = name;
    }


    void loadProgram()
    {
        cout << "[Debugger] Loading program: "
             << programName << endl;

        cout << "[Debugger] Program loaded successfully\n";
    }


    void addBreakpoint(int line)
    {
        breakpoints.push_back(line);

        cout << "[Breakpoint] Added at line "
             << line << endl;
    }


    bool checkBreakpoint(int line)
    {
        for(int bp : breakpoints)
        {
            if(bp == line)
                return true;
        }

        return false;
    }


    void execute(vector<string> code)
    {

        cout << "\n--- Running Program ---\n";


        for(int i = 0; i < code.size(); i++)
        {

            int line = i + 1;


            if(checkBreakpoint(line))
            {
                cout << "\n*** Breakpoint hit at line "
                     << line << " ***\n";

                debugConsole();

            }


            cout << "Executing: "
                 << code[i] << endl;
        }


        cout << "\nProgram finished\n";
    }



    void inspectVariable(string name)
    {

        if(variables.find(name)
           != variables.end())
        {
            cout << name
                 << " = "
                 << variables[name]
                 << endl;
        }

        else
        {
            cout << "Variable not found\n";
        }
    }



    void setVariable(string name,int value)
    {
        variables[name]=value;

        cout << "Variable created: "
             << name
             << " = "
             << value
             << endl;
    }



    void showMemory()
    {
        cout << "\nMemory Dump\n";

        for(auto item:variables)
        {
            cout << item.first
                 << " : "
                 << item.second
                 << endl;
        }
    }



    void debugConsole()
    {

        string command;


        while(true)
        {

            cout<<"\nDebugger> ";

            cin>>command;


            if(command=="continue")
            {
                break;
            }


            else if(command=="print")
            {
                string variable;

                cin>>variable;

                inspectVariable(variable);
            }


            else if(command=="memory")
            {
                showMemory();
            }


            else if(command=="exit")
            {
                exit(0);
            }


            else
            {
                cout<<"Unknown command\n";
            }

        }

    }


};



int main()
{

    Debugger debugger("test.cpp");


    debugger.loadProgram();


    vector<string> program =
    {

        "int x = 10;",
        "int y = 20;",
        "int result = x + y;",
        "cout << result;"

    };



    debugger.setVariable("x",10);
    debugger.setVariable("y",20);
    debugger.setVariable("result",30);



    debugger.addBreakpoint(3);


    debugger.execute(program);



    return 0;
}
