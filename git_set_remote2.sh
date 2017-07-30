git remote remove origin
git config --remove-section branch.master
git remote add origin https://CubeStayAlive:put_password_here@github.com/CubeStayAlive/STM32F7T1.git
git config branch.master.remote origin
git config branch.master.merge refs/heads/master 
#
git config --remove-section user
git config user.name CubeStayAlive
git config user.email CubeStayAlive@gmx.net 
git config push.default simple

echo ------
# echo must do manual remove in config
echo press
read

