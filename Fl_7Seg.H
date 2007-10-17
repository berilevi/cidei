//
// Fl_7Seg.H 2006-01-23 z_hossain
//
// Seven segment header file for the Fast Light Tool Kit (FLTK).
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


#ifndef Fl_7Seg_H
#define Fl_7Seg_H

#include <FL/Fl_Widget.H>

typedef unsigned short ushort;
typedef unsigned int uint;

#define DATA_SIZE 20

//inherit from valuator is not logical
class Fl_7Seg : public Fl_Widget {

	static const uchar data_seg[DATA_SIZE];

	int unit_w_, unit_h_;
	ushort thick_;
	ushort seg_gap_;
	ushort unit_gap_;
	ushort dot_len_;
	Fl_Color seg_color_;
	uchar align_;
	char *value_;

public:

	Fl_7Seg(int x, int y, int w, int h, const char *l=0);
	~Fl_7Seg(void);

	void draw();

	int unit_w() const { return unit_w_; }
	void unit_w(int w);

	int unit_h() const { return unit_h_; }
	void unit_h(int h);

	ushort thickness() const { return thick_; }
	void thickness(ushort t);

	uchar align_text(void) const { return align_; }
	void align_text(uchar a);

	ushort segment_gap() const { return seg_gap_; }
	void segment_gap(ushort g);

	ushort unit_gap(void) { return unit_gap_; }
	void unit_gap(ushort g);

	Fl_Color segment_color() const { return seg_color_;}
	void segment_color(Fl_Color c);
	
	ushort dot_len() const { return dot_len_; }
	void dot_len(ushort);

	const char *value(void) const; 
	void value(const char *a);
	
private:
	void draw_seg(uchar a, int x, int y, int w, int h);
};


#endif
