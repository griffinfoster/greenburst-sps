greenburst-sps
===

Cheetah-based pipeline for commensal single pulse search survey at the GBT.

#### Install

Pre-requisites:

* [astro-accelerate](https://github.com/AstroAccelerateOrg/astro-accelerate)
* [panda](https://gitlab.com/SKA-TDT/panda)
* [cheetah](https://gitlab.com/SKA-TDT/cheetah)

Setup [`astro-accelerate`](https://github.com/AstroAccelerateOrg/astro-accelerate):

```
export BASEDEV=<development base path>
mkdir $BASEDEV/development
cd $BASEDEV/development
mkdir astro-accelerate
mkdir astro-accelerate/aa_interface
cd astro-accelerate/aa_interface
mkdir build
mkdir install
git clone https://github.com/AstroAccelerateOrg/astro-accelerate.git checkout
cd checkout
git checkout aa_interface
cd ../build
cmake ../checkout -DCMAKE_INSTALL_PREFIX=../install
make -j
make install
```

Setup [`panda`](https://gitlab.com/SKA-TDT/panda):

```
cd $BASEDEV/development
mkdir panda
mkdir panda/master
cd panda/master
mkdir build
mkdir install
git clone https://gitlab.com/SKA-TDT/panda.git checkout
cd build
cmake ../checkout -DCMAKE_INSTALL_PREFIX=../install
make -j
make install
```

Setup [`cheetah`](https://gitlab.com/SKA-TDT/cheetah):

```
cd ~/development
mkdir cheetah
mkdir cheetah/master
cd cheetah/master
mkdir build
mkdir install
git clone https://gitlab.com/SKA-TDT/cheetah.git checkout
cd build
cmake ../checkout -DENABLE_CUDA=true -DENABLE_ASTROACCELERATE=true \
-DPANDA_INSTALL_DIR=$BASEDEV/development/panda/master/install -DCMAKE_INSTALL_PREFIX=../install \
-DASTROACCELERATE_INSTALL_DIR=$BASEDEV/development/astro-accelerate/aa_interface/install
make -j
make install
```

Finally, setup the SPS pipeline:

```
cd $BASEDEV/development
mkdir greenburst
mkdir greenburst/master
cd greenburst/master
mkdir build
git clone https://github.com/griffinfoster/greenburst-sps.git checkout
cd build
cmake ../checkout -DCHEETAH_INSTALL_DIR=$BASEDEV/development/cheetah/master/install \
-DPANDA_INSTALL_DIR=$BASEDEV/development/panda/master/install -DCMAKE_INSTALL_PREFIX=../install
make -j
```

Pipeline binary is located at:

```
/home/griffin/development/greenburst/build/greenburst/pipeline/greenburst
```

#### Usage

##### UDP Stream

```
$BASEDEV/development/greenburst/build/greenburst/pipeline/greenburst --pipeline empty \
--source.sigproc.file guppi_58086_B1933+16_0202_0001.fil --config lband-empty-sigproc.xml --source udp
```

##### Filterbank

```
$BASEDEV/development/greenburst/build/greenburst/pipeline/greenburst --pipeline sps \
--source.sigproc.file <filterbank file> --config lband-sps-sigproc.xml --source sigproc
```

#### Config

Example configuration files are in the `config` directory of the git repo.
