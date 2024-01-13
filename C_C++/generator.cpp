#include <bits/stdc++.h>
#include "lib/testlib.h"
// #include "testlib.h"
#define fastio ios::sync_with_stdio; cin.tie(0); cout.tie(0)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct invalid_command_generate_params
{
    stringstream* command_buffer;
    string* invaild_button_list;
    int invaild_button_list_size;
    int be_negative; // 0: can't, 1: can, -1: ?
};


int get_invaild_commands(invalid_command_generate_params* params)
{
    int invaild_command_amount = rnd.next(2, 5);
    int count = invaild_command_amount;
    while (count--)
    {
        switch (params->be_negative)
        {
            case 1:
                *(params->command_buffer) << '!';
                break;
            case -1:
                *(params->command_buffer) << rnd.next("!{0,1}");
                break;
        }
        *(params->command_buffer) << *((params->invaild_button_list) + rnd.next(0, params->invaild_button_list_size-1)) << '\n';
    }
    return invaild_command_amount;
}

/*
example: 0 x 3 = 0
part1: 2 x 1 = 2
part2: 2 x 48 = 98
*/
int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);

    fastio;
    
    if (argc < 2) return 1;
    if (!('0' <= argv[1][0] && argv[1][0] <= '1')) return 1;

    int section = argv[1][0] - '0';
    
    int n = 0;
    int status = 0;
    stringstream commands;
    int wrong_password_count = 0;
    string admin_password = "admin";
    string vault_password = "mypassword";
    bool vault_locked = false;

    struct invalid_command_generate_params params;
    params.command_buffer = &commands;

    int circle_amount = section == 0 ? rnd.next(2, 10) : rnd.next((int) 1e3, (int) 1e5);
    for (int i = 0; i < circle_amount; i++) 
    {
        int if_lock_vault = rnd.next(1, 10);
        if (if_lock_vault == 1)
        {
            commands << "X3\n";
            n++;
            vault_locked = true;
        }
        else if (if_lock_vault == 2)
        {
            commands << "!X3\n";
            n++;
            vault_locked = false;
        }
        
        int if_alarm = rnd.next(1, 20);
        if (if_alarm == 1)
        {
            string trigger = rnd.next("!X0|X4|X5");
            commands << trigger << '\n';
            n++;
            status = -1;
        }
        
        int if_turn_off = rnd.next(1, 50);
        if (if_turn_off == 1) 
        {
            commands << "OFF\n";
            n++;
            status = 0;
        }

        switch (status)
        {
            case 0:
            {
                wrong_password_count = 0;
                admin_password = "admin";
                vault_password = "mypassword";
                vault_locked = false;

                params.be_negative = -1;
                params.invaild_button_list_size = 6;
                string invaild_buttons[params.invaild_button_list_size] = {"X0", "X1", "X2", "X3", "X4", "X5"};
                params.invaild_button_list = invaild_buttons;
                n += get_invaild_commands(&params);

                commands << "ON\n";
                n++;
                status = 1;
                break;
            }
            case 1:
            {                
                params.be_negative = 0;
                params.invaild_button_list_size = 6;
                string invaild_buttons[params.invaild_button_list_size] = {"X0", "!X1", "!X2", "X2", "!X4", "!X5"};
                params.invaild_button_list = invaild_buttons;
                n += get_invaild_commands(&params);

                commands << "X1\n";
                n++;
                status = 2;
                break;
            }
            case 2:
            {
                params.be_negative = 0;
                params.invaild_button_list_size = 7;
                string invaild_buttons[params.invaild_button_list_size] = {"X0", "X1", "!X1", "!X2", "X2", "!X4", "!X5"};
                params.invaild_button_list = invaild_buttons;
                n += get_invaild_commands(&params);

                bool if_correct_password = rnd.next(0, 1) == 1;
                if (if_correct_password == 0)
                {
                    string input_password;
                    if (section == 0)
                        input_password = "wrong_password_" + rnd.next("[a-zA-Z0-9]{5}");
                    else 
                        input_password = rnd.next("[a-zA-Z0-9]{32}");
                    commands << '\"' << input_password << ' ' << "X1\n";
                    status = 3;
                    if (!vault_locked) wrong_password_count++;
                    if (wrong_password_count == 3) status = -1;
                }
                else
                {
                    wrong_password_count = 0;
                    int next_status = rnd.next(1, 2);
                    if (next_status == 1)
                    {
                        commands << '\"' << vault_password << ' ' << "X1\n";
                        if (!vault_locked) status = 4;
                    }
                    if (next_status == 2)
                    {
                        commands << '\"' << admin_password << ' ' << "X1\n";
                        status = 5;
                    }
                }
                break;
            }
            
            case 3: // wrong password
            {
                params.be_negative = 0;
                params.invaild_button_list_size = 6;
                string invaild_buttons[params.invaild_button_list_size] = {"X0", "X1", "!X1", "!X2", "!X4", "!X5"};
                params.invaild_button_list = invaild_buttons;
                n += get_invaild_commands(&params);
                                
                commands << "X2\n"; 
                n++;
                status = 2;
                break;
            }
            
            case 4:
            {
                params.be_negative = 0;
                params.invaild_button_list_size = 8;
                string invaild_buttons[params.invaild_button_list_size] = {"X0", "X1", "!X1", "!X2", "!X4", "X4", "!X5", "X5"};
                params.invaild_button_list = invaild_buttons;
                n += get_invaild_commands(&params);
                                
                commands << "X2\n"; 
                n++;
                status = 2;
                break;
            }
            
            case 5:
            {
                params.be_negative = 0;
                params.invaild_button_list_size = 7;
                string invaild_buttons[params.invaild_button_list_size] = {"X0", "X1", "!X1", "!X2", "X2", "!X4", "!X5"};
                params.invaild_button_list = invaild_buttons;
                n += get_invaild_commands(&params);
                
                if (section == 0) vault_password = "password_" + rnd.next("[a-zA-Z0-9]{5}");
                else vault_password = rnd.next("[a-zA-Z0-9]{32}");
                commands << '\"' << vault_password << " X1\n";
                n++;
                break;
            }
            
            case -1:
            {
                params.be_negative = -1;
                params.invaild_button_list_size = 6;
                string invaild_buttons[params.invaild_button_list_size] = {"X0", "X1", "X2", "X3", "X4", "X5"};
                params.invaild_button_list = invaild_buttons;
                n += get_invaild_commands(&params);
                
                commands << "OFF\n";
                n++;
                break;
            }
        }
    } 
    
    cout << n << '\n' << commands.str();

    return 0;
}