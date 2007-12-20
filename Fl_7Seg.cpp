//
// Fl_7Seg.cxx 2006-01-23 z_hossain
//
// Seven segment widget for the Fast Light Tool Kit (FLTK).
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Library General Public
// License as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Library General Public License for more details.
//
// You should have received a copy of the GNU Library General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
//


#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "Fl_7Seg.H"

//decimal and hexadecimal digits
const uchar Fl_7Seg::data_seg[DATA_SIZE] = {
	0x00,
	0x7E,												//0
	0x30,												//1
	0x6D,												//2
	0x79,												//3
	0x33,												//4
	0x5B,												//5
	0x5F,												//6
	0x70,												//7
	0x7F,												//8
	0x7B,												//9
	0x77,												//A
	0x1F,												//B
	0x4E,												//C
	0x3D,												//D
	0x4F,												//E
	0x47,												//F
	0x01,												//-
	0xA0,												//.
	0x00,												//' '			//repeat the first one
};

Fl_7Seg::Fl_7Seg(int x, int y, int w, int h, const char *l) : Fl_Widget(x, y, w, h, l) {

	unit_h_ = (int)(Fl_7Seg::h() * (7.00 / 10.00));
	unit_w_ = (int)(unit_h_ * (3.00 / 5.00));

	//seg_color_ = FL_BLACK;
	seg_color_ = FL_WHITE;
	align_ = FL_ALIGN_CENTER;

	thickness((int)(unit_w_ * (3.00 / 10.00)));

	seg_gap_ = 1;
	unit_gap_ = 4;
	dot_len_ = int((unit_w_ + 2)/ 3.0);
	
	value(" ");
}

//give high flexibility of formating for char instead of integer
void Fl_7Seg::value(const char *a) {
	int i;

	if(value_ != NULL) {
		if(sizeof(value_) <= strlen(a) || sizeof(value_) > 1024) {
			//value_ = (char *)realloc(value_, strlen(a));
			free(value_);
			value_ = (char *)malloc(strlen(a));
		}
	}
	else {
		value_ = (char *)malloc(strlen(a));
	}

	for(i = 0; a[i]; i++) {
		if(a[i] >= 0x30 && a[i] <= 0x39) {
			value_[i] = a[i] - 0x2F;
		}
		else if(a[i] >= 0x41 && a[i] <= 0x46) {
			value_[i] = a[i] - 0x36;
		}
		else if(a[i] >= 0x61 && a[i] <= 0x66) {
			value_[i] = a[i] - 0x56;
		}
		else if(a[i] == '-') {
			value_[i] = 0x11;
		}
		else if(a[i] == ' ') {
			value_[i] = 0x13;
		}
		else if(a[i] == '.') {
			value_[i] = 0x12;
		}
		else {
			value_[i] = 0x13;
		}
	}
	value_[i] = '\0';

	damage(FL_DAMAGE_USER1);
}

void Fl_7Seg::draw(void) {
	int tx = x() + Fl::box_dx(box());
	int ty = y() + Fl::box_dy(box());
	int tw = w() - Fl::box_dw(box());
	int th = h() - Fl::box_dh(box());

	uchar d = damage();

	fl_color(color());
	if((d & FL_DAMAGE_ALL) || (d & FL_DAMAGE_USER1)) {
		fl_rectf(tx, ty, tw, th);
	}
	fl_push_clip(tx, ty, tw, th);

	int txtw = (unit_w_ + unit_gap_) * strlen(value_) - unit_gap_;

	switch(align_) {
		case FL_ALIGN_LEFT:
			break;
		case FL_ALIGN_RIGHT:
			tx += (tw - txtw);
			break;
		case FL_ALIGN_CENTER:
			tx += ((tw - txtw) >> 1);
			break;
		default:
			fprintf(stderr, "Illegal Align Value");
	}
	ty += ((th - unit_h_) >> 1);

	if(d & FL_DAMAGE_USER2) {
		fl_rectf(tx - 1, ty - 1, txtw + 2, unit_h_ + 2);
	}

	fl_color(active_r() ? seg_color_ : fl_inactive(seg_color_));
	int xx = tx;
	
	for(int i = 0; value_[i]; i++) {
		if(value_[i] == 0x12) {
			fl_rectf(xx, ty + unit_h_ + 1 - dot_len_, dot_len_, dot_len_); //you may use pie
			xx += (dot_len_ + unit_gap_);
		}
		else {
			draw_seg(data_seg[(int)value_[i]], xx, ty, unit_w_, unit_h_); //casting just to avoid warring
			xx += (unit_w_ + unit_gap_);
		}
	}
	fl_pop_clip();

	if(d & FL_DAMAGE_ALL) {
		draw_box();
		draw_label();
	}
}

void Fl_7Seg::draw_seg(uchar a, int x, int y, int w, int h) {
	int x0, y0, x1, y1, x2, y2, x3, y3;
	int h2 = h >> 1;
	int thick_2 = thick_ >> 1;
	
	if(a & 0x40) {
		x0 = x + seg_gap_;
		y0 = y;
		x1 = x0 + thick_;
		y1 = y0 + thick_;
		x2 = x + w - thick_ - seg_gap_;
		y2 = y1;
		x3 = x2 + thick_;
		y3 = y0;

		fl_polygon(x0, y0, x1, y1, x2, y2, x3, y3);
	}

	if(a & 0x20) {
		x0 = x + w;
		y0 = y + seg_gap_;
		x1 = x0 - thick_;
		y1 = y0 + thick_;
		x2 = x1;
		y2 = y + h2 - thick_2 - seg_gap_;
		x3 = x0;
		y3 = y2 + thick_2;

		fl_polygon(x0, y0, x1, y1, x2, y2, x3, y3);
	}
	if(a & 0x10) {
		x0 = x + w;
		y0 = y + h2 + seg_gap_;
		x1 = x0 - thick_;
		y1 = y0 + thick_2;
		x2 = x1;
		y2 = y + h - thick_ - seg_gap_;
		x3 = x0;
		y3 = y2 + thick_;

		fl_polygon(x0, y0, x1, y1, x2, y2, x3, y3);
	}
	if(a & 0x08) {
		x0 = x + seg_gap_;
		y0 = y + h;
		x1 = x0 + thick_;
		y1 = y0 - thick_;
		x2 = x + w - thick_ - seg_gap_;
		y2 = y1;
		x3 = x2 + thick_;
		y3 = y0;

		fl_polygon(x0, y0, x1, y1, x2, y2, x3, y3);
	}
	if(a & 0x04) {
		x0 = x;
		y0 = y + h2 + seg_gap_;
		x1 = x0 + thick_;
		y1 = y0 + thick_2;
		x2 = x1;
		y2 = y + h - thick_ - seg_gap_;
		x3 = x0;
		y3 = y2 + thick_;

		fl_polygon(x0, y0, x1, y1, x2, y2, x3, y3);
	}
	if(a & 0x02) {
		x0 = x;
		y0 = y + seg_gap_;
		x1 = x0 + thick_;
		y1 = y0 + thick_;
		x2 = x1;
		y2 = y + h2 - thick_2 - seg_gap_;
		x3 = x0;
		y3 = y2 + thick_2;

		fl_polygon(x0, y0, x1, y1, x2, y2, x3, y3);
	}
	if(a & 0x01) {
		x0 = x + seg_gap_;
		y0 = y + h2;
		x1 = x0 + thick_;
		y1 = y0 - thick_2;
		x2 = x1;
		y2 = y1 + thick_;

		fl_polygon(x0, y0, x1, y1, x2, y2);

		//it is not good to use fl_rectf with adjustment
		x0 = x1;
		y0 = y1;
		x1 = x0 + w - thick_ * 2 - seg_gap_ * 2;
		y1 = y0;
		x2 = x1;
		y2 = y1 + thick_;
		x3 = x0;
		y3 = y2;

		fl_polygon(x0, y0, x1, y1, x2, y2, x3, y3);

		x0 = x + w - seg_gap_;
		y0 = y + h2;
		x1 = x0 - thick_;
		y1 = y0 - thick_2;
		x2 = x1;
		y2 = y1 + thick_;

		fl_polygon(x0, y0, x1, y1, x2, y2);
	}
}

const char * Fl_7Seg::value(void) const {
	int len = strlen(value_);
	char *buf = (char *)malloc(len + 1);
	for(int i = 0; i < len; i++) {
		if(value_[i] >= 0x1 && value_[i] <= 0xA) {
			buf[i] = value_[i] + 0x2F;
		}
		else if(value_[i] >= 0xB && value_[i] <= 0x10) {
			buf[i] = value_[i] + 0x36;
		}
		else if(value_[i] == 0x11) {
			buf[i] = '-';
		}
		else if(value_[i] == 0x12) {
			buf[i] = '.';
		}
		else if(value_[i] == 0x13) {
			buf[i] = ' ';
		}
	}
	buf[len] = '\0';
	return buf;
}

void Fl_7Seg::align_text(uchar a) {
	align_ = a;
	damage(FL_DAMAGE_USER1);
}

void Fl_7Seg::thickness(ushort t) { 
	thick_ = t & 0xFFFFFFFE; //force even
	damage(FL_DAMAGE_USER1); //in special case FL_DAMAGE_USER2 is unable
}

void Fl_7Seg::segment_gap(ushort g) {
	seg_gap_ = g;
	damage(FL_DAMAGE_USER1); //in special case FL_DAMAGE_USER2 is unable
}

void Fl_7Seg::unit_gap(ushort g) {
	unit_gap_ = g;
	damage(FL_DAMAGE_USER1);
}

void Fl_7Seg::segment_color(Fl_Color c) {
	seg_color_ = c;
	damage(FL_DAMAGE_USER2);
}

void Fl_7Seg::unit_w(int w) {
	unit_w_ = w;
	damage(FL_DAMAGE_USER1);
}

void Fl_7Seg::dot_len(ushort len) {
	dot_len_ = len;
	damage(FL_DAMAGE_USER1);
}

void Fl_7Seg::unit_h(int h) {
	unit_h_ = h;
	damage(FL_DAMAGE_USER1);
}

Fl_7Seg::~Fl_7Seg(void) {
	free(value_);
}
