/* ================================================ *
 * nanosvg++                                        *
 * This software is a fork of nanosvg (note below). *
 * No license-related aspects are affected.         *
 * Kamil Koczurek | koczurekk@gmail.com             *
 * ================================================ */
/* ============================================================================ *
 * Copyright (c) 2013-14 Mikko Mononen memon@inside.org                         *
 *                                                                              *
 * This software is provided 'as-is', without any express or implied            *
 * warranty.  In no event will the authors be held liable for any damages       *
 * arising from the use of this software.                                       *
 *                                                                              *
 * Permission is granted to anyone to use this software for any purpose,        *
 * including commercial applications, and to alter it and redistribute it       *
 * freely, subject to the following restrictions:                               *
 *                                                                              *
 * 1. The origin of this software must not be misrepresented; you must not      *
 * claim that you wrote the original software. If you use this software         *
 * in a product, an acknowledgment in the product documentation would be        *
 * appreciated but is not required.                                             *
 * 2. Altered source versions must be plainly marked as such, and must not be   *
 * misrepresented as being the original software.                               *
 * 3. This notice may not be removed or altered from any source distribution.   *
 *                                                                              *
 * The polygon rasterization is heavily based on stb_truetype rasterizer        *
 * by Sean Barrett - http://nothings.org/                                       *
 * ============================================================================ */

//! @file
//!
//! \brief
//! Nanosvg++ rasterizer declaration

#ifndef NANOSVGRASTR_HPP
#define NANOSVGRASTR_HPP

#include "nanosvg.hpp"

namespace nsvg {
	typedef struct NSVGrasterizer NSVGrasterizer;

	#define NSVG__SUBSAMPLES	5
	#define NSVG__FIXSHIFT		10
	#define NSVG__FIX			(1 << NSVG__FIXSHIFT)
	#define NSVG__FIXMASK		(NSVG__FIX-1)
	#define NSVG__MEMPAGE_SIZE	1024

	typedef struct NSVGedge {
		float x0,y0, x1,y1;
		int dir;
		struct NSVGedge* next;
	} NSVGedge;

	typedef struct NSVGpoint {
		float x, y;
		float dx, dy;
		float len;
		float dmx, dmy;
		unsigned char flags;
	} NSVGpoint;

	typedef struct NSVGactiveEdge {
		int x,dx;
		float ey;
		int dir;
		struct NSVGactiveEdge *next;
	} NSVGactiveEdge;

	typedef struct NSVGmemPage {
		unsigned char mem[NSVG__MEMPAGE_SIZE];
		int size;
		struct NSVGmemPage* next;
	} NSVGmemPage;

	typedef struct NSVGcachedPaint {
		PaintType type;
		SpreadType spread;
		float xform[6];
		unsigned int colors[256];
	} NSVGcachedPaint;

	struct NSVGrasterizer
	{
		float px, py;

		float tessTol;
		float distTol;

		NSVGedge* edges;
		int nedges;
		int cedges;

		NSVGpoint* points;
		int npoints;
		int cpoints;

		NSVGpoint* points2;
		int npoints2;
		int cpoints2;

		NSVGactiveEdge* freelist;
		NSVGmemPage* pages;
		NSVGmemPage* curpage;

		unsigned char* scanline;
		int cscanline;

		unsigned char* bitmap;
		int width, height, stride;
	};

	/* Example Usage:
		// Load SVG
		struct SNVGImage* image = nsvgParseFromFile("test.svg.");

		// Create rasterizer (can be used to render multiple images).
		struct NSVGrasterizer* rast = nsvgCreateRasterizer();
		// Allocate memory for image
		unsigned char* img = malloc(w*h*4);
		// Rasterize
		nsvgRasterize(rast, image, 0,0,1, img, w, h, w*4);
	*/

	// Allocated rasterizer context.
	NSVGrasterizer* nsvgCreateRasterizer();

	// Rasterizes SVG image, returns RGBA image (non-premultiplied alpha)
	//   r - pointer to rasterizer context
	//   image - pointer to image to rasterize
	//   tx,ty - image offset (applied after scaling)
	//   scale - image scale
	//   dst - pointer to destination image data, 4 bytes per pixel (RGBA)
	//   w - width of the image to render
	//   h - height of the image to render
	//   stride - number of bytes per scaleline in the destination buffer
	void nsvgRasterize(NSVGrasterizer* r,
					   Image* image, float tx, float ty, float scale,
					   unsigned char* dst, int w, int h, int stride);

	// Deletes rasterizer context.
	void nsvgDeleteRasterizer(NSVGrasterizer*);
}

#endif // NANOSVGRASTR_HPP
