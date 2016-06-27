/*
   Copyright (c) 2015-2016, The Linux Foundation. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/

#ifndef _QTI_CONNECTIVITY_ADAPTER_H
#define _QTI_CONNECTIVITY_ADAPTER_H

#include <string>

#include <sysutils/SocketClient.h>
#include <sysutils/SocketListener.h>

#include "CommandListener.h"
#include "NetdCommand.h"

NetdCommand *getQtiConnectivityCmd(CommandListener *broadcaster);
void natStarted(const char* tetherIface, const char* upstreamIface);
void natStopped(const char* tetherIface, const char* upstreamIface);
int getV6TetherStats(SocketClient *cli, const char* tetherIface, const char* upstreamIface,
        std::string &extraProcessingInfo);

#ifdef USE_WRAPPER
int connAdapterGetHostByName(const pid_t pid, const uid_t uid, const gid_t gid, const char* mName);
int connAdapterGetHostByAddr(const pid_t pid, const uid_t uid, const gid_t gid, const void* addr);
int connAdapterGetAddrInfo(const pid_t pid, const uid_t uid, const gid_t gid, const char* hostname, const struct addrinfo* hints);
void connAdapterSendDnsReport(const int latencyMs);
#endif

class QtiConnectivityCommand : NetdCommand {
public:
   QtiConnectivityCommand() : NetdCommand("qticonnectivity") {}
   virtual ~QtiConnectivityCommand() {}
   int runCommand(SocketClient* client, int argc, char** argv);
   NetdCommand *asNetdCommand();
};
#endif