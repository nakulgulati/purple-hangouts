#ifndef _PURPLECOMPAT_H_
#define _PURPLECOMPAT_H_

#include <glib.h>
#include "version.h"

#if PURPLE_VERSION_CHECK(3, 0, 0)
#include <glib-object.h>

#define purple_circular_buffer_destroy		g_object_unref
#define purple_hash_destroy			g_object_unref

#else

#include "connection.h"

#define PURPLE_TYPE_CONNECTION	purple_value_new(PURPLE_TYPE_SUBTYPE, PURPLE_SUBTYPE_CONNECTION)
#define PURPLE_IS_CONNECTION	PURPLE_CONNECTION_IS_VALID

#define PURPLE_CONNECTION_CONNECTED        PURPLE_CONNECTED
#define PURPLE_CONNECTION_FLAG_HTML        PURPLE_CONNECTION_HTML
#define PURPLE_CONNECTION_FLAG_NO_BGCOLOR  PURPLE_CONNECTION_NO_BGCOLOR
#define PURPLE_CONNECTION_FLAG_NO_FONTSIZE PURPLE_CONNECTION_NO_FONTSIZE

#define purple_request_cpar_from_connection(a)  purple_connection_get_account(a), NULL, NULL
#define purple_connection_get_protocol		purple_connection_get_prpl
#define purple_connection_error                 purple_connection_error_reason
#define purple_connection_is_disconnecting(c)   FALSE
#define purple_connection_set_flags(pc, f)      ((pc)->flags = (f))
#define purple_connection_get_flags(pc)         ((pc)->flags)

#define PurpleChatConversation  PurpleConvChat
#define PurpleIMConversation    PurpleConvIm
#define purple_conversations_find_chat_with_account(id, account) \
		((PurpleConvChat *)purple_find_conversation_with_account(PURPLE_CONV_TYPE_CHAT, id, account))
#define purple_chat_conversation_get_id  purple_conv_chat_get_id
#define purple_conversations_find_im_with_account(name, account)  \
		PURPLE_CONV_IM(purple_find_conversation_with_account(PURPLE_CONV_TYPE_IM, name, account))
#define purple_im_conversation_new(account, from) PURPLE_CONV_IM(purple_conversation_new(PURPLE_CONV_TYPE_IM, account, from))
#define PURPLE_CONVERSATION(chatorim) (chatorim == NULL ? NULL : chatorim->conv)

#define PurpleIMTypingState	PurpleTypingState
#define PURPLE_IM_NOT_TYPING	PURPLE_NOT_TYPING
#define PURPLE_IM_TYPING	PURPLE_TYPING
#define PURPLE_IM_TYPED		PURPLE_TYPED

#define purple_protocol_got_user_status		purple_prpl_got_user_status

#define purple_account_set_password(account, password, dummy1, dummy2) \
		purple_account_set_password(account, password);

#define purple_proxy_info_get_proxy_type        purple_proxy_info_get_type

#define purple_serv_got_im      serv_got_im
#define purple_serv_got_typing  serv_got_typing
#define purple_serv_got_alias   serv_got_alias
#define purple_serv_got_chat_in serv_got_chat_in

#define PurpleXmlNode                xmlnode
#define purple_xmlnode_new           xmlnode_new
#define purple_xmlnode_new_child     xmlnode_new_child
#define purple_xmlnode_from_str      xmlnode_from_str
#define purple_xmlnode_to_str        xmlnode_to_str
#define purple_xmlnode_get_child     xmlnode_get_child
#define purple_xmlnode_get_next_twin xmlnode_get_next_twin
#define purple_xmlnode_get_data      xmlnode_get_data
#define purple_xmlnode_get_attrib    xmlnode_get_attrib
#define purple_xmlnode_set_attrib    xmlnode_set_attrib
#define purple_xmlnode_insert_data   xmlnode_insert_data
#define purple_xmlnode_free          xmlnode_free


#endif

#endif /*_PURPLECOMPAT_H_*/