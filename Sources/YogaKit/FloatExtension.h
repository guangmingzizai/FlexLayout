//
//  FloatExtension.h
//  Pods
//
//  Created by wangjianfei on 2018/5/3.
//

#ifndef FloatExtension_h
#define FloatExtension_h

#import <Foundation/Foundation.h>

CGFloat roundedDownToFractionalPoint(CGFloat value);

/**
 Returns the current float rounded up to the nearest fraction of a pixel
 that the screen density supports.
 */
CGFloat roundedUpToFractionalPoint(CGFloat value) {
    if (value == 0) {
        return 0;
    }
    if (value < 0) {
        return roundedDownToFractionalPoint(-(-value));
    }
    CGFloat scale = UIScreen.mainScreen.scale;
    // The smallest precision in points (aka the number of points per hardware pixel).
    CGFloat pointPrecision = 1.0 / scale;
    if (value <= pointPrecision) {
        return pointPrecision;
    }
    return ceil(value * scale) / scale;
}

/**
 Returns the current float rounded down to the nearest fraction of a pixel
 that the screen density supports.
 */
CGFloat roundedDownToFractionalPoint(CGFloat value) {
    if (value == 0) {
        return 0;
    }
    if (value < 0) {
        return roundedUpToFractionalPoint(-(-value));
    }
    CGFloat scale = UIScreen.mainScreen.scale;
    // The smallest precision in points (aka the number of points per hardware pixel).
    CGFloat pointPrecision = 1.0 / scale;
    if (value < pointPrecision) {
        return 0;
    }
    return floor(value * scale) / scale;
}

/**
 Returns the current float rounded up or down to the nearest fraction of a pixel
 that the screen density supports.
 */
CGFloat roundedToFractionalPoint(CGFloat value) {
    if (value == 0) {
        return 0;
    }
    CGFloat up = roundedUpToFractionalPoint(value);
    CGFloat down = roundedDownToFractionalPoint(value);
    return (up - value <= value - down ? up : down);
}

#endif /* FloatExtension_h */
