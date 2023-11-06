deluser jkowalski
cd ..
rm -r jkowalski
deluser --remove-home jkowalski
openssl passwd –crypt haslo1
sudo useradd -m -p encrypted -c "Jan Kowalski" -s /bin/bash -g student jkowalski
sudo userdel -r jkowalski
tty
nano crypt-gnu.c
gcc -o crypt-gnu crypt-gnu.c -lcrypt
./crypt-gnu
nano crypt-xopen.c
gcc -o crypt-xopen crypt-xopen.c -lcrypt
./crypt-xopen
wget dpaste.com/897JG9S9L.txt -O hello.c
gcc -o hello hello.c
./hello
nano baza.txt
wget dpaste.com/link.txt -O addusers.c
gcc -o addusers addusers.c -lcrypt
./addusers
wget dpaste.com/link.txt -O delusers.c
gcc -o delusers delusers.c
./delusers
sudo shutdown