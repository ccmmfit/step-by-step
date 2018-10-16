Slove 
$ cd .ssh
bash: cd: .ssh: No such file or directory
-----------------------------------------------------

$  ssh-keygen -t rsa -C "ccmmfit@fomail.com"
Generating public/private rsa key pair.
Enter file in which to save the key (/c/Users/WangYining/.ssh/id_rsa):
Created directory '/c/Users/WangYining/.ssh'.
Enter passphrase (empty for no passphrase):
Enter same passphrase again:
Your identification has been saved in /c/Users/WangYining/.ssh/id_rsa.
Your public key has been saved in /c/Users/WangYining/.ssh/id_rsa.pub.
The key fingerprint is:
SHA256:Xih+rKzGMOYLOs3OteeRWNI9pmZVtYPu4Z1mJr5UujI ccmmfit@fomail.com
The key's randomart image is:
+---[RSA 2048]----+
|            .    |
|           o .   |
|          o o    |
|     . . +   .   |
|    . + S + .    |
|  +  = O = = .   |
|.= +o B + * *    |
|oo+.o=.+Eo *     |
|.o+oo++  o+.     |
+----[SHA256]-----+


WangYining@LS MINGW64 ~
$ cd ~/.ssh

WangYining@LS MINGW64 ~/.ssh
$ ls
id_rsa  id_rsa.pub
