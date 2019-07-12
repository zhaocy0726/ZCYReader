//
//  XDSRecordModel.h
//  XDSReader
//
//  Created by dusheng.xu on 2017/6/15.
//  Copyright © 2017年 macos. All rights reserved.
//

#import <Foundation/Foundation.h>

/// MARK: 阅读记录
@interface XDSRecordModel : NSObject<NSCopying,NSCoding>

/** 阅读的章节 */
@property (nonatomic, strong) XDSChapterModel *chapterModel;
/** 章节中的位置 */
@property (nonatomic) NSInteger location;
/** 阅读的章节 */
@property (nonatomic, assign) NSInteger currentChapter;

/** 阅读的页数 */
@property (nonatomic, readonly) NSInteger currentPage;
/** 该章总页数 */
@property (nonatomic, readonly) NSInteger totalPage;
/** 总章节数 */
@property (nonatomic, readonly) NSInteger totalChapters;

@end
