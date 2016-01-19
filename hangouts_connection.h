
#ifndef _HANGOUTS_CONNECTION_H_
#define _HANGOUTS_CONNECTION_H_

#include <glib.h>

#include "purple-socket.h"
#include "http.h"

#include "libhangouts.h"
#include "hangouts_pblite.h"
#include "hangouts.pb-c.h"

#define HANGOUTS_PBLITE_XORIGIN_URL "https://talkgadget.google.com"
#define HANGOUTS_CHANNEL_URL_PREFIX "https://0.client-channel.google.com/client-channel/"

void hangouts_process_data_chunks(const gchar *data, gsize len);

void hangouts_process_channel(int fd);


void hangouts_longpoll_request(HangoutsAccount *ha);
void hangouts_fetch_channel_sid(HangoutsAccount *ha);
void hangouts_send_maps(HangoutsAccount *ha, JsonArray *map_list);
void hangouts_add_channel_services(HangoutsAccount *ha);


typedef void(* HangoutsPbliteResponseFunc)(HangoutsAccount *ha, ProtobufCMessage *response, gpointer user_data);
void hangouts_pblite_request(HangoutsAccount *ha, const gchar *endpoint, ProtobufCMessage *request, HangoutsPbliteResponseFunc callback, ProtobufCMessage *response_message, gpointer user_data);


typedef void(* HangoutsPbliteChatMessageResponseFunc)(HangoutsAccount *ha, SendChatMessageResponse *response, gpointer user_data);
void hangouts_pblite_send_chat_message(HangoutsAccount *ha, SendChatMessageRequest *request, HangoutsPbliteChatMessageResponseFunc callback, gpointer user_data);


#endif /*_HANGOUTS_CONNECTION_H_*/