# vi: set filetype=sh :: Vi/ViM
#-
# Copyright (c) 2012-2017 Parker Lee Ranney TTEE
# Copyright (c) 2017-2019 Devin Teske <dteske@FreeBSD.org>
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
# OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
# OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
# SUCH DAMAGE.
#
############################################################ IDENT(1)
#
# $Title: nsadmin configuration file $
# $Id: nsadmin-var.inc,v 1.3 2012/05/11 02:37:17 root Exp $
# $Copyright: 2017-2019 Devin Teske. All rights reserved. $
# $FrauBSD: nsadmin/nsadmin-var.inc 2019-07-16 18:44:24 -0700 freebsdfrau $
#
############################################################ INFORMATION
#
# nsadmin-var.inc -- Variables for use by nsadmin.
#
############################################################ GLOBALS

pgm="${0##*/}" # Program basename
progdir="${0%/*}" # Program directory

PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

#
# Global exit status
#
SUCCESS=0
FAILURE=1

############################################################ CONFIGURATION

admin=ops@example.com			# Admin email address
bindgroup=named				# Bind files/executable group
binduser=named				# Bind files/executable owner
exclude="RCS build"			# Exclude from changes or edits
					# in $nsadmindir
colist=					# Array of RCS co'd files
critical=page-ops@example.com		# Critical failure email address
editmode=				# Run in edit mode
failfile=				# File that failed zonetest()
failtype=				# Type of file that failed
nameddir=/etc/named			# Bind's namedb directory
nsadmindir=/etc/nsadmin			# nsadmin directory
ransig=					# Ran sigquit() or not
subnets=				# Subnets changed for rev maps
sync=					# Run in sync mode
update=					# Stage of master file updates
updzones=				# Updated zones
user=cm					# Push process user account
vfail=					# Verify failed
views="ext int"				# Views to create

#
# Zone File Settings
#
contact=root.example.com		# DNS admins
expire=1209600				# Zone expire
minimum=900				# Zone minimum
primary=ns1.example.com			# Primary master
secondary=ns2.example.com		# Secondary (see nsadmin-gen.inc)
refresh=900				# Zone refresh
retry=600				# Zone retry
ttl=360					# Zone TTL

#
# Generated
#
cwd="$PWD"				# Current working directory
lock="$nsadmindir/.nsadmin-lock"	# Lock file for DNS edits
log="$nsadmindir/.nsadmin-log"		# Log file
sep=$( printf %75s | tr " " - )		# Separator
sepdbl=$( printf %20s | tr " " = )	# Double separator
serial=$( date +%s )			# Zone file serial number
slaves="$secondary"
					# DNS slave resolvers
scpopts="-i /home/$user/.ssh/id_rsa -q -F /home/$user/.ssh/config"
					# SCP arguments
sshopts="-l $user -i /home/$user/.ssh/id_rsa -q"
sshopts="$sshopts -F /home/$user/.ssh/config"
					# SSH arguments
tmp="$nsadmindir/build/tmp"		# Temporary directory

################################################################################
# END
################################################################################