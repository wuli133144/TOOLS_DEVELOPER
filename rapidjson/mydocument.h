#ifndef MY_DOCUMENT_H_
#define MY_DOCUMENT_H_

#include "reader.h"
#include "internal/meta.h"
#include "internal/strfunc.h"
#include "document.h"
#include "prettywriter.h"
#include "stringbuffer.h"
#include <iostream>
#include "rapidjson/writer.h"
class MyDocument 
{
public:
     MyDocument(){}
     ~MyDocument(){} //Destroy();}

public:
    Document document;
	StringBuffer buffer;

public:
	void Jsonfy(string buf){

		buffer.clear();
		PrettyWriter<StringBuffer> writer(buffer);
		document.Accept(writer);
		DEBUG("test_jsonfy: %s",buffer.GetString());
		buf = buffer.GetString();
        return;
	}	
};




#endif
