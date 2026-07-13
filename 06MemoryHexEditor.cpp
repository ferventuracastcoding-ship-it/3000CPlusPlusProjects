#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;


class HexEditor
{

private:

    vector<unsigned char> memory;


public:


    HexEditor(int size)
    {
        memory.resize(size,0);
    }


    void fillDemoData()
    {
        for(int i=0;i<memory.size();i++)
        {
            memory[i]=i%256;
        }
    }



    void display(int start,int length)
    {

        cout<<"\nADDRESS      HEX DATA\n";
        cout<<"-----------------------------\n";


        for(int i=start;i<start+length;i+=16)
        {

            cout<<hex
                <<setw(8)
                <<setfill('0')
                <<i
                <<"  ";


            for(int j=0;j<16;j++)
            {

                if(i+j < memory.size())
                {
                    cout<<setw(2)
                        <<(int)memory[i+j]
                        <<" ";
                }

            }


            cout<<endl;

        }

        cout<<dec;

    }




    void editByte(int address,
                  unsigned char value)
    {

        if(address>=0 &&
           address<memory.size())
        {

            memory[address]=value;


            cout<<"Memory updated\n";

        }

        else
        {
            cout<<"Invalid address\n";
        }

    }




    void searchByte(unsigned char value)
    {

        cout<<"Found at addresses:\n";


        for(int i=0;i<memory.size();i++)
        {

            if(memory[i]==value)
            {
                cout<<"0x"
                    <<hex
                    <<i
                    <<endl;
            }

        }

        cout<<dec;

    }




    void save(string file)
    {

        ofstream output(file,
                        ios::binary);


        output.write(
            (char*)memory.data(),
            memory.size()
        );


        output.close();


        cout<<"Saved memory dump\n";
    }




};



int main()
{

    HexEditor editor(256);


    editor.fillDemoData();


    int choice;


    while(true)
    {

        cout<<"\n=== MEMORY HEX EDITOR ===\n";
        cout<<"1. View Memory\n";
        cout<<"2. Edit Byte\n";
        cout<<"3. Search Byte\n";
        cout<<"4. Save Dump\n";
        cout<<"5. Exit\n";

        cout<<"Choice: ";
        cin>>choice;



        if(choice==1)
        {

            int start,length;

            cout<<"Start address: ";
            cin>>start;

            cout<<"Length: ";
            cin>>length;


            editor.display(start,length);

        }



        else if(choice==2)
        {

            int address;
            int value;


            cout<<"Address: ";
            cin>>address;


            cout<<"New HEX value: ";
            cin>>hex>>value;


            editor.editByte(
                address,
                (unsigned char)value
            );

            cout<<dec;

        }



        else if(choice==3)
        {

            int value;

            cout<<"HEX value: ";
            cin>>hex>>value;


            editor.searchByte(
                (unsigned char)value
            );


            cout<<dec;

        }



        else if(choice==4)
        {

            editor.save(
                "memory_dump.bin"
            );

        }



        else if(choice==5)
        {
            break;
        }

    }


    return 0;
}