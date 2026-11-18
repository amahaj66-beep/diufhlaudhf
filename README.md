# diufhlaudhf
sometinme

you must install IRremote library from ArminJo   \
screenshot added  showing how

there are 3 empty if statements in bot brain   
to find the condition open IR tester build a circuit as constructed 
connect R pin of Ir reciever to 3.3 V     *also do this genarally for all IR receivers so they dont burn out
G -> ground      Y -> pin 6 on arduino
uplaod IRremot_test to arduino and open serial moniter
when the IR recever recieves a signal it flashes read
in the serial moniter the command will be given like command: XX
what ever two charcters apear in the places of the the XX are the condition for the if statements
each command should corespond with a button on the remote
example if the command is 12 then in the if statement put if(command == 0x12)
example 2 if it is 1 chaacter like c the command == 0x0C

I beleieve the remote is hexadecimal not sure tho
