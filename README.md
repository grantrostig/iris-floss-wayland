# Iris Floss for Wayland
Floss is implementation of blue light reduction software like Iris, f.lux, Redshift and Night Shift with minimum dependencies for all Linux distributions.

This version of Iris Floss is the only one that works with Wayland and Mir. It will also run with X11, but if you are using X11 prefer the original version
https://github.com/danielng01/iris-floss

Iris Floss for Wayland works thanks to DDC/CI protocol and DDCControl


Since this project is open source you need to build it from source. To build Iris Floss

Install all needed dependencies on

Ubuntu

```
sudo apt-get install libddccontrol-dev ddccontrol
```

Fedora

```
sudo dnf install ddccontrol
```


This will install ddccontrol, for other distributions install the corresponding package. Then

```
make
```

from the **iris-floss-wayland.c** folder and then

```
sudo ./iris-floss-wayland
```

Note that you need to always start iris-floss-wayland as Root.

# How to use

You can customize Color temperature and Brightness with command line arguments

```
sudo ./iris-floss-wayland 5000 90
```

Will set Color temperature to **5000K** and Brightness to **90%**

If something is not working check the output by adding **-v** as third parameter.

```
sudo ./iris-floss-wayland 100 10 -v
```

Will set Color temperature to **100K** and Brightness to **10%** and will print verbose output

To reset all color changes

```
sudo ./iris-floss-wayland 6500 100 -v
```

Specially for all all people who like Linux.

http://iristech.co/iris-floss
