//
//  XDSHaloButton.h
//  XDSReader
//
//  Created by dusheng.xu on 2017/6/19.
//  Copyright © 2017年 macos. All rights reserved.
//

#import <UIKit/UIKit.h>

// 颜色
@interface XDSHaloButton : UIControl

@property (nonatomic, strong) UIImageView *imageView;// imageView
@property (nonatomic, strong) UIColor *haloColor;// 光晕颜色
@property (nonatomic, strong) UIImage *nomalImage;// 默认图片
@property (nonatomic, strong) UIImage *selectImage;// 选中图片

- (instancetype)initWithFrame:(CGRect)frame haloColor:(UIColor *)haloColor;

- (void)openHalo;
- (void)closeHalo;

@end
