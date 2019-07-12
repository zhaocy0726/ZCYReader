//
//  XDSBookModel.h
//  XDSReader
//
//  Created by dusheng.xu on 2017/6/15.
//  Copyright © 2017年 macos. All rights reserved.
//

#import <Foundation/Foundation.h>

/// MARK: 书籍基本信息
@interface LPPBookInfoModel : NSObject <NSCoding>

/** 解压包所在路径 */
@property (nonatomic, copy) NSString *rootDocumentUrl;
/** OPF与NCX文件所在的文件夹路径 */
@property (nonatomic, copy) NSString *OEBPSUrl;

/** 封面 */
@property (nonatomic, copy) NSString *cover;
/** 题名 */
@property (nonatomic, copy) NSString *title;
/** 责任者 */
@property (nonatomic, copy) NSString *creator;
/** 主题词或关键词 */
@property (nonatomic, copy) NSString *subject;
/** 内容描述 */
@property (nonatomic, copy) NSString *descrip;
/** 日期 */
@property (nonatomic, copy) NSString *date;
/** 类型 */
@property (nonatomic, copy) NSString *type;
/** 格式 */
@property (nonatomic, copy) NSString *format;
/** 标识符 */
@property (nonatomic, copy) NSString *identifier;
/** 来源 */
@property (nonatomic, copy) NSString *source;
/** 相关信息 */
@property (nonatomic, copy) NSString *relation;
/** 履盖范围 */
@property (nonatomic, copy) NSString *coverage;
/** 权限描述 */
@property (nonatomic, copy) NSString *rights;

@end


/// MARK: 图书综合信息
@interface XDSBookModel : NSObject <NSCoding>

/** 资源路径 */
@property (nonatomic, strong) NSURL *resource;
/** 电子书文本内容 */
@property (nonatomic, copy) NSString *content;
/** 书籍基本信息 */
@property (nonatomic, strong) LPPBookInfoModel *bookBasicInfo;
/** 阅读进度 */
@property (nonatomic, strong) XDSRecordModel *record;
/** 电子书类型（txt, epub） */
@property (nonatomic, assign) LPPEBookType bookType;

/** 章节 */
@property (nonatomic, readonly) NSArray <XDSChapterModel*> *chapters;
/** 包含笔记的章节 */
@property (nonatomic, readonly) NSArray <XDSChapterModel*> *chapterContainNotes;
/** 包含书签的章节 */
@property (nonatomic, readonly) NSArray <XDSChapterModel*> *chapterContainMarks;


+ (void)updateLocalModel:(XDSBookModel *)bookModel url:(NSURL *)url;
/** 通过文件地址获取解析后的图书模型 */
+ (id)getLocalModelWithURL:(NSURL *)url;
- (instancetype)initWithContent:(NSString *)content;
- (instancetype)initWithePub:(NSString *)ePubPath;


- (void)loadContentInChapter:(XDSChapterModel *)chapterModel;
- (void)loadContentForAllChapters;

- (void)deleteNote:(XDSNoteModel *)noteModel;
- (void)addNote:(XDSNoteModel *)noteModel;

- (void)deleteMark:(XDSMarkModel *)markModel;
- (void)addMark:(XDSMarkModel *)markModel;

@end
