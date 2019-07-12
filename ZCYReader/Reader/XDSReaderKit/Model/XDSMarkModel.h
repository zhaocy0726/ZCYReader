//
//  XDSMarkModel.h
//  XDSReader
//
//  Created by dusheng.xu on 2017/6/15.
//  Copyright © 2017年 macos. All rights reserved.
//

#import <Foundation/Foundation.h>

/// MARK: 书签
@interface XDSMarkModel : NSObject<NSCoding>

/** 添加书签的日期 */
@property (nonatomic, strong) NSDate *date;
/** 划线的内容 */
@property (nonatomic, copy) NSString *content;
/** 书签所在的章节 */
@property (nonatomic, assign) NSInteger chapter;
/** 书签在章节中所在的位置 */
@property (nonatomic, assign) NSInteger locationInChapterContent;
/** 根据locationInChapterContent获取书签在章节中所在的页码 */
@property (nonatomic, readonly) NSInteger page;

@end
