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

*****See
$ cd ~/.ssh

$ ls
id_rsa  id_rsa.pub

---------------------------------------------------------------------------
Slove
git commit -m'first'

*** Please tell me who you are.

Run

  git config --global user.email "you@example.com"
  git config --global user.name "Your Name"

to set your account's default identity.
Omit --global to set the identity only in this repository.

fatal: unable to auto-detect email address 
-----------------------------------------------------
$ git init
Reinitialized existing Git repository in F:/Create/git/Step-by-step/.git/

$ git config user.name "ccmmfit"

$ git config user.email "mail@...com"

$ git add *

$ git commit -m "some init msg"
[master (root-commit) 58ca6d5] some init msg
 1 file changed, 35 insertions(+)
 create mode 100644 text.md

*****Set
$ git config --global user.email "mail@qq.com"
$ git config --global user.name "ccmmfit"

*****commit
$ git commit -m'first'
$ git push origin master



