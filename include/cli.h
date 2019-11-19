/*
* Copyright (c) 2019 Sprint
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*    http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef __CLI_H
#define __CLI_H

#include "emgmt.h"
#include "elogger.h"

//#include "epc_app.h"

class CliStatsGet : public EManagementHandler
{
public:
   CliStatsGet(ELogger &audit); 

   virtual Void process(const Pistache::Http::Request& request, Pistache::Http::ResponseWriter &response);

private:
   CliStatsGet();
};

class CliStatsResetPut : public EManagementHandler
{
public:
   CliStatsResetPut(ELogger &audit); 

   virtual Void process(const Pistache::Http::Request& request, Pistache::Http::ResponseWriter &response);

private:
   CliStatsResetPut();
};

#endif // #ifndef __CLI_H
