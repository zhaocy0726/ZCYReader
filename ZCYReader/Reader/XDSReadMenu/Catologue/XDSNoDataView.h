//
//  XDSNoDataView.h
//  XDSReader
//
//  Created by dusheng.xu on 2017/6/23.
//  Copyright © 2017年 macos. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface XDSNoDataView : UIView

+ (instancetype)newInstance;

@property (nonatomic, weak) IBOutlet UILabel *titleLabel;
@property (nonatomic, weak) IBOutlet UILabel *contentLabel;

@end
