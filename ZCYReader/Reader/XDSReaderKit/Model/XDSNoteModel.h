//
//  XDSNoteModel.h
//  XDSReader
//
//  Created by dusheng.xu on 2017/6/15.
//  Copyright © 2017年 macos. All rights reserved.
//

#import <Foundation/Foundation.h>

/// MARK: 笔记
@interface XDSNoteModel : NSObject<NSCoding>

/** 添加笔记的日期 */
@property (nonatomic, strong) NSDate *date;
/** 笔记 */
@property (nonatomic, copy) NSString *note;
/** 划线的内容 */
@property (nonatomic, copy) NSString *content;
/** 笔记所在的章节 */
@property (nonatomic, assign) NSInteger chapter;
/** 笔记在章节中所在的位置 */
@property (nonatomic, assign) NSInteger locationInChapterContent;

/** 根据locationInChapterContent获取笔记在章节中所在的页码 */
@property (nonatomic, readonly) NSInteger page;


- (NSURL *)getNoteURL;

+ (XDSNoteModel *)getNoteFromURL:(NSURL *)noteUrl ;

@end
