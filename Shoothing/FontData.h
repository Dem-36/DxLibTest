#ifndef _FONTDATA_H_
#define _FONTDATA_H_

#include<string>

struct FontData {
	FontData(std::string fontName,int fontSize,int thick)
		:fontName(fontName),fontSize(fontSize),thick(thick){}
	std::string fontName;
	int fontSize;
	int thick;

	bool operator < (const FontData& value)const {
#if 1
		return std::tie(fontName, fontSize, thick) < std::tie(value.fontName, value.fontSize, value.thick);
#else
		if (fontName < value.fontName)
			return true;
		if (fontName == value.fontName) {
			if (fontSize < value.fontSize)
				return true;
			if (thick < value.thick)
				return true;
		}
		return false;
#endif
	}
};

#endif