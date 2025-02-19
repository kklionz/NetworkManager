/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * Copyright (C) 2017 Intel Corporation
 */

#ifndef __NETWORKMANAGER_IWD_MANAGER_H__
#define __NETWORKMANAGER_IWD_MANAGER_H__

#include "devices/nm-device.h"
#include "nm-wifi-utils.h"
#include "nm-wifi-ap.h"

#define NM_IWD_BUS_TYPE G_BUS_TYPE_SYSTEM
#define NM_IWD_SERVICE  "net.connman.iwd"

#define NM_IWD_DAEMON_INTERFACE              "net.connman.iwd.Daemon"
#define NM_IWD_AGENT_MANAGER_INTERFACE       "net.connman.iwd.AgentManager"
#define NM_IWD_WIPHY_INTERFACE               "net.connman.iwd.Adapter"
#define NM_IWD_DEVICE_INTERFACE              "net.connman.iwd.Device"
#define NM_IWD_NETWORK_INTERFACE             "net.connman.iwd.Network"
#define NM_IWD_AGENT_INTERFACE               "net.connman.iwd.Agent"
#define NM_IWD_WSC_INTERFACE                 "net.connman.iwd.SimpleConfiguration"
#define NM_IWD_KNOWN_NETWORK_INTERFACE       "net.connman.iwd.KnownNetwork"
#define NM_IWD_SIGNAL_AGENT_INTERFACE        "net.connman.iwd.SignalLevelAgent"
#define NM_IWD_AP_INTERFACE                  "net.connman.iwd.AccessPoint"
#define NM_IWD_ADHOC_INTERFACE               "net.connman.iwd.AdHoc"
#define NM_IWD_STATION_INTERFACE             "net.connman.iwd.Station"
#define NM_IWD_P2P_INTERFACE                 "net.connman.iwd.p2p.Device"
#define NM_IWD_P2P_PEER_INTERFACE            "net.connman.iwd.p2p.Peer"
#define NM_IWD_P2P_SERVICE_MANAGER_INTERFACE "net.connman.iwd.p2p.ServiceManager"
#define NM_IWD_P2P_WFD_INTERFACE             "net.connman.iwd.p2p.Display"

#define NM_IWD_AGENT_PATH NM_DBUS_PATH "/iwd/agent"

#define NM_TYPE_IWD_MANAGER (nm_iwd_manager_get_type())
#define NM_IWD_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), NM_TYPE_IWD_MANAGER, NMIwdManager))
#define NM_IWD_MANAGER_CLASS(klass) \
    (G_TYPE_CHECK_CLASS_CAST((klass), NM_TYPE_IWD_MANAGER, NMIwdManagerClass))
#define NM_IS_IWD_MANAGER(obj)         (G_TYPE_CHECK_INSTANCE_TYPE((obj), NM_TYPE_IWD_MANAGER))
#define NM_IS_IWD_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), NM_TYPE_IWD_MANAGER))
#define NM_IWD_MANAGER_GET_CLASS(obj) \
    (G_TYPE_INSTANCE_GET_CLASS((obj), NM_TYPE_IWD_MANAGER, NMIwdManagerClass))

#define NM_IWD_MANAGER_P2P_DEVICE_ADDED "p2p-device-added"

typedef struct _NMIwdManager      NMIwdManager;
typedef struct _NMIwdManagerClass NMIwdManagerClass;

GType nm_iwd_manager_get_type(void);

NMIwdManager *nm_iwd_manager_get(void);

gboolean nm_iwd_manager_is_known_network(NMIwdManager        *self,
                                         const char          *name,
                                         NMIwdNetworkSecurity security);

NMSettingsConnection *nm_iwd_manager_get_ap_mirror_connection(NMIwdManager *self, NMWifiAP *ap);

GDBusProxy *
nm_iwd_manager_get_dbus_interface(NMIwdManager *self, const char *path, const char *name);

gboolean nm_iwd_manager_get_netconfig_enabled(NMIwdManager *self);

gboolean nm_iwd_manager_check_wfd_info_compatible(NMIwdManager *self, const NMIwdWfdInfo *wfd_info);
gboolean nm_iwd_manager_register_wfd(NMIwdManager *self, const NMIwdWfdInfo *wfd_info);
void     nm_iwd_manager_unregister_wfd(NMIwdManager *self);

bool nm_iwd_manager_is_recently_mirrored(NMIwdManager *self, const GBytes *ssid);

#endif /* __NETWORKMANAGER_IWD_MANAGER_H__ */
