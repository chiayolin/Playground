setup
hostname db12c
xhost +
su - oracle
xhost +
su - oracle
vi /etc/sysctl.conf
sysctl-p
/sbin/sysctl -p
vi /etc/security/limits.conf
mount /dev/cdrom /media
cd /media/Packages
rpm -Uvh binutils-2.20.51.0.2-5.42.e16.x86_64.rpm
rpm -Uvh binutils-2.20.51.0.2-5.42.el6.x86_64.rpm 
rpm -Uvh compat-libcap1-1.10-1.x86_64.rpm
rpm -Uvh compat-libstdc++-33-3.2.3-69.el6.x86_64.rpm
rpm -Uhv compat-libstdc++-33-3.2.3-69.el6.i686.rpm
rpm -Uvh gcc-4.4.7-11.el6.x86_64.rpm
rpm -Uvh gcc-c++-4.4.7-11.el6.x86_64.rpm
rpm -Uvh glibc-2.12-1.149.el6.i686.rpm
rpm -Uhv glibc-2.12-1.149.el6.x86_64.rpm
rpm -Uvh glibc-devel-2.12-1.149.el6.x86_64.rpm
rpm -Uvh glibc-devel-2.12-1.149.el6.i686.rpm
rpm -Uvh ksh-20120801-21.el6.x86_64.rpm
rpm -Uvh libgcc-4.4.7-11.el6.i686.rpm
rpm -Uvh libgcc-4.4.7-11.el6.x86_64.rpm
rpm -Uvh libstdc++-4.4.7-11.el6.x86_64.rpm
rpm -Uvh libstdc++-4.4.7-11.el6.i686.rpm
rpm -Uvh libstdc++-devel-4.4.7-11.el6.x86_64.rpm
rpm -Uvh libstdc++-devel-4.4.7-11.el6.i686.rpm
rpm -Uvh libaio-0.3.107-10.el6.x86_64.rpm
rpm -Uvh libaio-0.3.107-10.el6.i686.rpm
rpm -Uvh libaio-devel-0.3.107-10.el6.x86_64.rpm
rpm -Uvh libaio-devel-0.3.107-10.el6.i686.rpm
rpm -Uvh libXext-1.3.2-2.1.el6.x86_64.rpm
rpm -Uvh libXext-1.3.2-2.1.el6.i686.rpm --nodeps
rpm -Uvh libXtst-1.2.2-2.1.el6.x86_64.rpm
rpm -Uvh libXtst-1.2.2-2.1.el6.i686.rpm --nodeps
rpm -Uvh libX11-1.6.0-2.2.el6.x86_64.rpm
rpm -Uvh libX11-1.6.0-2.2.el6.i686.rpm --nodeps
rpm -Uvh libXau-1.0.6-4.el6.x86_64.rpm
rpm -Uvh libXau-1.0.6-4.el6.i686.rpm
rpm -Uvh libxcb-1.9.1-2.el6.x86_64.rpm
rpm -Uvh libxcb-1.9.1-2.el6.i686.rpm
rpm -Uvh libXi-1.7.2-2.2.el6.x86_64.rpm
rpm -Uvh libXi-1.7.2-2.2.el6.i686.rpm
rpm -Uvh make-3.81-20.el6.x86_64.rpm
rpm -Uvh sysstat-9.0.4-27.el6.x86_64.rpm
rpm -Uvh xorg-x11-fonts-misc-7.2-9.1.el6.noarch.rpm
rpm -Uvh tigervnc-server-1.1.0-16.el6.x86_64.rpm --nodeps
groupadd -g 54321 oinstall
groupadd -g 54322 dba
groupadd -g 54323 oper
groupadd -g 54324 backupdba
groupadd -g 54325 dgdba
groupadd -g 54326 kmdba
groupadd -g 54327 asmdba
groupadd -g 54328 asmoper
groupadd -g 54329 asmadmin
useradd -u 54321 -g oinstall -G dba,oper oracle
cd /home
pwd
ls
unzip linuxamd64_12102_database_1or2.zip
unzip linuxamd64_12102_database_1of2.zip
unzip linuxamd64_12102_database_2of2.zip
/etc/hosts
vi /etc/hosts
ls
pwd
vi /etc/sysconfig/network
hostname db12c
cd
cd root
root
cd /home
root
pwd
cd /network
ls
hostname db12c
cd root
cd /root
hostname db12c
mkdir -p /u01/app/oracle/product/12.1.0.2/db_1
chown -R oracle:oinstall /u01
chmod -R 777 /u01
vi /home/oracle/.bash_profile
service iptables stop
chkconfig iptable off
chkconfig iptables off
vncserver
/u01/app/oraInventory/orainstRoot.sh
/u01/app/oracle/product/12.1.0.2/dbhome_1/root.sh 
dbca
exit
xhost +
su - oracle
xhost +
su - oracle
cd /home
vi /home/oracle/.bash_profile 
find -name listener.ora
find / -name listener.ora
cd network
cd u01
cd
cd /u01
ca /app/oracle
cd /app/oracle
ls
cd /app
cd
cd /home
cd /dbhome_1
cd
cd /dbhome_1
cd /u01
ls
pwd
cd /app
cd /network
vi app/oracle/product/12.1.0.2/dbhome_1/network/admin/samples/listener.ora 
lsnrctl start
umount -l tmpfs
mount -t tmpfs  tmpfs -o size=3584m /dev/shm 
vi /etc/fstab
cd /home
ls
fdicsk /dev/sdb
fdisk /dev/sdb
mkswap -c /dev/sdb1
swapon /dev/sdb1
swapon -s
vi /etc/fstab
cd /home
mkdir database_11gr2
unzip -d database_11gr2
unzip -d database_11gr2 linux.x64_11gr2_database_1of2.zip
unzip -d database_11gr2linux.x64_11gr2_database_1of2.zip
ls
unzip -d database_11gr2/linux.x64_11gR2_database_1of2.zip
man unzip
unzip -d database_11gr2 linux.x64_11gR2_database_1of2.zip 
unzip -d database_11gr2 linux.x64_11gR2_database_2of2.zip 
rpm -Uvh unixODBC-2.2.14-14.el6.x86_64.rpm
rpm -Uvh unixODBC-devel-2.2.14-14.el6.x86_64.rpm
rpm -Uvh unixODBC-devel-2.2.14-14.el6.i686.rpm --nodeps
rpm -Uvh unixODBC-2.2.14-14.el6.i686.rpm --nodeps
ls
ping 10.10.10.12
