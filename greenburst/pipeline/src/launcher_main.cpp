#include "greenburst/pipeline/GreenburstLauncherTraits.h"
#include <panda/Launcher.h>

typedef ska::panda::Launcher<greenburst::pipeline::GreenburstLauncherTraits> LauncherType;

int main(int argc, char** argv)
{
    LauncherType launcher;    
    if(int rv=launcher.parse(argc, argv)) return rv;
    return launcher.exec();
}
