/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_irc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:18:20 by vnadal            #+#    #+#             */
/*   Updated: 2023/05/30 15:08:57 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IRC_H
#define FT_IRC_H

/* ************************************************************************** */
/*                              LIBRARY INCLUDE                               */
/* ************************************************************************** */

#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <cstring>
#include <map>
#include <cstdlib>
#include <csignal>
#include <cstdio>
#include <cerrno>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

/* ************************************************************************** */
/*                                HPP INCLUDE                                 */
/* ************************************************************************** */
#include "Error.hpp"
#include "./Server/Server.hpp"
#include "./Client/Client.hpp"
#include "./Channel/Channel.hpp"
#include "./Command/Command.hpp"
#include "./colors.h"

/* ************************************************************************** */
/*                                  DEFINE                                    */
/* ************************************************************************** */
#define ERR_ARGS "Invalid number of arguments. Precise port and password"
#define ERR_SOCKET "Socket system called failed"
#define ERR_BIND "Bind system called failed"
#define ERR_LISTEN "Listen called failed"
#define ERR_SELECT "Select system called failed"
#define ERR_ACCEPT "Accept system called failed"
#define ERR_SETSOCKOPT "Setsockopt system called failed"

#define ERR_MSG_TOO_LONG "[\e[38;5;1mERROR\e[0m] Message too long, sizemax : 1 000\n"

#define CMD_INVALID_ARGS "[\e[38;5;1mERROR\e[0m] Invalid number of arguments\n"

#define PASS_LOGGED "[\e[38;5;2mPASS_CMD\e[0m] Successfully Logged\n"
#define PASS_WRONG "[\e[38;5;1mPASS_CMD\e[0m] Invalid Password\n"
#define PASS_ALREADY_LOGGED "[\e[38;5;3mPASS_CMD\e[0m] Already Logged\n"
#define PASS_TRIES "[\e[38;5;3mPASS_CMD\e[0m] Tries left : "

#define NICK_USAGE "[\e[38;5;1mNICK_CMD\e[0m] Usage : NICK <your nickname>\n"
#define NICK_ISUSED "[\e[38;5;3mNICK_CMD\e[0m] Nickname is already used\n"
#define NICK_SET "[\e[38;5;2mNICK_CMD\e[0m] Nickname set successfully\n"
#define NICK_CHANGE "[\e[38;5;2mNICK_CMD\e[0m] Nickname changed successfully\n"

#define USER_USAGE "[\e[38;5;1mUSER_CMD\e[0m] USAGE : USER <userName> <hostName> <serverName> <realName>\n"
#define USER_ALREADY_REGISTER "[\e[38;5;3mUSER_CMD\e[0m] You are already registered\n"
#define USER_SUCCESSFULLY_REGISTER "[\e[38;5;2mUSER_CMD\e[0m] Successfully registered\n"

#define JOIN_USAGE "[\e[38;5;1mJOIN_CMD\e[0m] Usage : JOIN <channel1,channel2,...> <password1,password2,...>\n"
#define JOIN_NO_SUCH_CHANNEL "[\e[38;5;3mJOIN_CMD\e[0m] No such channel : "
#define JOIN_TOO_MANY "[\e[38;5;3mJOIN_CMD\e[0m] You already are in too many channels\n"
#define JOIN_ALREADY_IN_CHANN "[\e[38;5;3mJOIN_CMD\e[0m] You are already in this channel : "
#define JOIN_NOT_INVITED "[\e[38;5;3mJOIN_CMD\e[0m] You have not been invited to this channel : "
#define JOIN_MAX_USER_REACH "[\e[38;5;3mJOIN_CMD\e[0m] This channel is full : "
#define JOIN_INVALID_KEY "[\e[38;5;3mJOIN_CMD\e[0m] Invalid channel password : "
#define JOIN_CHANN_CREAT "[\e[38;5;2mJOIN_CMD\e[0m] Channel created : "

#define MODE_USAGE "[\e[38;5;1mMODE_CMD\e[0m] Usage : MODE <channel> <[+|-]c|i|k|l|o|t>\n"
#define MODE_NO_SUCH_CHANNEL "[\e[38;5;1mMODE_CMD\e[0m] No such channel : "
#define MODE_NOT_IN_CHANNEL "[\e[38;5;1mMODE_CMD\e[0m] You're not in the channel : "
#define MODE_NO_PRIVILEGES "[\e[38;5;1mMODE_CMD\e[0m] You're not OP in the channel : "
#define MODE_NOT_ENOUGH_ARGS "[\e[38;5;1mMODE_CMD\e[0m] Not enough argment from flags\n"
#define MODE_INVITE_TRUE "[\e[38;5;2mMODE_CMD\e[0m] Invite mode set to \e[38;5;40mTRUE\e[0m\n"
#define MODE_INVITE_FALSE "[\e[38;5;2mMODE_CMD\e[0m] Invite mode set to \e[38;5;160mFALSE\e[0m\n"
#define MODE_KEY_SET "[\e[38;5;2mMODE_CMD\e[0m] Channel Password \e[38;5;40mset\e[0m\n"
#define MODE_KEY_UNSET "[\e[38;5;2mMODE_CMD\e[0m] Channel Password \e[38;5;160munset\e[0m\n"
#define MODE_OP_NOT_IN_CHANNEL "[\e[38;5;3mMODE_CMD\e[0m] Specified user is not in the channel : "
#define MODE_OP_SET "[\e[38;5;2mMODE_CMD\e[0m] Channel Operator \e[38;5;40mset\e[0m : "
#define MODE_OP_UNSET "[\e[38;5;2mMODE_CMD\e[0m] Channel Operator \e[38;5;160munset\e[0m : "
#define MODE_TOPIC_SET "[\e[38;5;2mMODE_CMD\e[0m] Channel Topic set to \e[38;5;40mTRUE\e[0m\n"
#define MODE_TOPIC_UNSET "[\e[38;5;2mMODE_CMD\e[0m] Channel Operator set to \e[38;5;160mFALSE\e[0m\n"
#define MODE_LIMIT_WRONG_CHAR "[\e[38;5;3mMODE_CMD\e[0m] Characters not allowed in the limit : "
#define MODE_LIMIT_WRONG "[\e[38;5;3mMODE_CMD\e[0m] Limit must be between 1 and 2147483647\n"
#define MODE_LIMIT_SET "[\e[38;5;2mMODE_CMD\e[0m] Channel User Limit set to : "
#define MODE_LIMIT_UNSET "[\e[38;5;2mMODE_CMD\e[0m] Channel User Limit \e[38;5;160munset\e[0m\n"
#define MODE_COLOR_SET "[\e[38;5;2mMODE_CMD\e[0m] Channel Color set to : "
#define MODE_COLOR_UNSET "[\e[38;5;2mMODE_CMD\e[0m] Channel Color \e[38;5;160munset\e[0m\n"

#define TOPIC_USAGE "[\e[38;5;1mTOPIC_CMD\e[0m] Usage : TOPIC <channel> | TOPIC <channel> <new topic>\n"
#define TOPIC_NOT_IN_CHANNEL "[\e[38;5;1mTOPIC_CMD\e[0m] You're not in the channel\n"
#define TOPIC_NO_PRIVILEGES "[\e[38;5;1mTOPIC_CMD\e[0m] You're not OP in the channel\n"
#define TOPIC_NOT_SET "[\e[38;5;3mTOPIC_CMD\e[0m] The topic of this channel has not been set\n"
#define TOPIC_SET "[\e[38;5;2mTOPIC_CMD\e[0m] The topic has been set to : "
#define TOPIC_IS "[\e[38;5;2mTOPIC_CMD\e[0m] Topic is : "

#define KICK_USAGE "[\e[38;5;1mKICK_CMD\e[0m] Usage : KICK <channel1,channel2,...> <user1,user2,...>\n"
#define KICK_SELF "[\e[38;5;3mKICK_CMD\e[0m] You cannot kick yourself from a channel\n"
#define KICK_NOT_IN_CHANNEL "[\e[38;5;3mKICK_CMD\e[0m] You are not in the channel : "
#define KICK_NO_PRIVILEGES "[\e[38;5;1mKICK_CMD\e[0m] You're not OP in the channel : "
#define KICK_NOT_USER_IN_CHANNEL "[\e[38;5;3mKICK_CMD\e[0m] You cannot kick someone who's not on the channel : "

#define INVITE_ONE "[\e[38;5;1mINVITE_CMD\e[0m] "
#define INVITE_TWO "[\e[38;5;2mINVITE_CMD\e[0m] "
#define INVITE_THREE "[\e[38;5;3mINVITE_CMD\e[0m] "
#define INVITE_USAGE "[\e[38;5;1mINVITE_CMD\e[0m] Usage : INVITE <channel1,channel2,...> <user1,user2,...>\n"
#define INVITE_NO_SUCH_CHAN "[\e[38;5;3mINVITE_CMD\e[0m] No such channel : "
#define INVITE_NOT_SET  "[\e[38;5;3mINVITE_CMD\e[0m] Invitations are not activated on the channel : "
#define INVITE_NOT_IN_CHANNEL "[\e[38;5;3mINVITE_CMD\e[0m] You're not in the channel : "
#define INVITE_NO_PRIVILEGES "[\e[38;5;3mINVITE_CMD\e[0m] You're not OP in the channel : "
#define INVITE_NO_USER_EXIST "[\e[38;5;3mINVITE_CMD\e[0m] This user does not exists : "

#define PART_USAGE "[\e[38;5;1mPART_CMD\e[0m] Usage : PART <channel1,channel2,...>\n"
#define PART_NOT_IN_CHANNEL "[\e[38;5;3mPART_CMD\e[0m] You cannot leave a channel you're not in : "
#define PART_LEFT_CHANNEL "[\e[38;5;2mPART_CMD\e[0m] You left the channel : "

#define PRIVMSG_USAGE "[\e[38;5;1mPRIVMSG_CMD\e[0m] Usage : PRIVMSG <user1|channel1,user2|channel2,...> <your message>\n"
#define PRIVMSG_NO_USER_CHAN "[\e[38;5;3mPRIVMSG_CMD\e[0m] No such Chan or User : "

#define BOT_DISABLED "[\e[38;5;1mBOT_CMD\e[0m] The bot is disabled.\n"

#define	GOT_KICKED	"You have been kicked of \""
#define INFO "[\e[38;5;3mINFO\e[0m] "

#define FAIL -1
#define SUCCESS 0
#define MAX_CHANNEL 15
#define DEBUG_MODE false
#define SERVER_MODE true

enum CLIENT_STATUS
{
	GUEST,
	LOGGED,
	NICK,
	REGISTERED
};

#endif
