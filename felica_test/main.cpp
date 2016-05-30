#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

#include <iomanip>

extern "C" {
#include <libpafe/libpafe.h>
#include <libpafe/pasori_command.h>
#include <libpafe/felica_command.h>
}

using namespace std;

int main()
{
    pasori* p;

    if((p = pasori_open()) != NULL){
        felica* f;
        pasori_init(p);
        stringstream stream;
        while(true){
            if((f = felica_polling(p, FELICA_POLLING_ANY, 0, 3)) != NULL){
                uint8_t idm[8];
                felica_get_idm(f,idm);
                for(int value : idm){
                    stream<<setfill('0')<<setw(2)<<hex<<value;
                }
                cout<<" "<<stream.str()<<"\r"<<flush;
                stream.str("");stream.clear(stringstream::goodbit);

                free(f);
            }
            usleep(500000);
        }
    }
    pasori_close(p);
    return 0;
}
